// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann

#include <muscovite_harbor/search/connection_pool.hpp>

#include <chrono>
#include <condition_variable>
#include <mutex>
#include <queue>
#include <spdlog/spdlog.h>

namespace muscovite_harbor::search {

struct OpenSearchConnectionPool::Impl {
    PoolConfig config;
    std::queue<std::unique_ptr<OpenSearchClient>> available;
    std::size_t active_count = 0;
    std::size_t pending_requests = 0;
    bool shutdown = false;

    mutable std::mutex mutex;
    std::condition_variable cv;

    // Metrics (lifetime counters)
    std::uint64_t acquired = 0;
    std::uint64_t released = 0;
    std::uint64_t created = 0;
    std::uint64_t destroyed = 0;
    std::uint64_t idle_expired = 0;
    std::uint64_t below_min_count = 0;
    std::uint64_t acquisition_time_us = 0;
    std::uint64_t wait_time_us = 0;
    std::atomic<std::uint64_t> max_wait_time_us{0};
    std::uint64_t acquisition_failures = 0;

    explicit Impl(PoolConfig cfg) : config(std::move(cfg)) {}
};

// ── PooledOpenSearchClient ───────────────────────────────────

PooledOpenSearchClient::PooledOpenSearchClient(PooledOpenSearchClient&& other) noexcept
    : m_client(std::move(other.m_client)), m_pool(other.m_pool) {
    other.m_pool = nullptr;
}

PooledOpenSearchClient& PooledOpenSearchClient::operator=(PooledOpenSearchClient&& other) noexcept {
    if (this != &other) {
        m_client = std::move(other.m_client);
        m_pool = other.m_pool;
        other.m_pool = nullptr;
    }
    return *this;
}

PooledOpenSearchClient::~PooledOpenSearchClient() {
    if (m_pool && m_client) {
        m_pool->return_connection(std::move(m_client));
    }
}

auto PooledOpenSearchClient::get() -> OpenSearchClient& {
    return *m_client;
}

auto PooledOpenSearchClient::get() const -> const OpenSearchClient& {
    return *m_client;
}

auto PooledOpenSearchClient::operator->() -> OpenSearchClient* {
    return m_client.get();
}

auto PooledOpenSearchClient::operator->() const -> const OpenSearchClient* {
    return m_client.get();
}

PooledOpenSearchClient::PooledOpenSearchClient(std::unique_ptr<OpenSearchClient> client,
                                              OpenSearchConnectionPool* pool)
    : m_client(std::move(client)), m_pool(pool) {}

// ── OpenSearchConnectionPool ────────────────────────────────

auto OpenSearchConnectionPool::create(PoolConfig config)
    -> std::expected<OpenSearchConnectionPool, SearchError> {
    if (config.max_connections == 0) {
        return std::unexpected(SearchConnectionError("max_connections must be > 0"));
    }

    auto pool = OpenSearchConnectionPool{};
    pool.m_impl = std::make_unique<Impl>(config);

    // Warm up the pool with min_connections
    for (std::size_t i = 0; i < config.min_connections; ++i) {
        SearchConfig search_config;
        search_config.host = config.host;
        search_config.port = config.port;
        search_config.timeout_seconds = static_cast<long>(config.connection_timeout.count());

        try {
            auto client = std::make_unique<OpenSearchClient>(search_config);
            pool.m_impl->available.push(std::move(client));
            ++pool.m_impl->created;
        } catch (const SearchConnectionError& e) {
            spdlog::warn("Failed to create warm-up connection {}/{}: {}", i + 1,
                        config.min_connections, e.what());
        }
    }

    spdlog::info("OpenSearch connection pool created: min={}, max={}",
                 config.min_connections, config.max_connections);
    return pool;
}

OpenSearchConnectionPool::OpenSearchConnectionPool() = default;

OpenSearchConnectionPool::OpenSearchConnectionPool(OpenSearchConnectionPool&& other) noexcept
    : m_impl(std::move(other.m_impl)) {}

OpenSearchConnectionPool& OpenSearchConnectionPool::operator=(OpenSearchConnectionPool&& other) noexcept {
    if (this != &other) {
        m_impl = std::move(other.m_impl);
    }
    return *this;
}

OpenSearchConnectionPool::~OpenSearchConnectionPool() {
    shutdown();
}

auto OpenSearchConnectionPool::acquire()
    -> std::expected<PooledOpenSearchClient, SearchError> {
    return acquire(std::chrono::milliseconds{30000}); // Default 30 seconds
}

auto OpenSearchConnectionPool::acquire(std::chrono::milliseconds timeout)
    -> std::expected<PooledOpenSearchClient, SearchError> {
    const auto start_time = std::chrono::steady_clock::now();
    std::unique_lock lock{m_impl->mutex};

    if (m_impl->shutdown) {
        return std::unexpected(SearchConnectionError("Connection pool has been shut down"));
    }

    auto deadline = std::chrono::steady_clock::now() + timeout;
    ++m_impl->pending_requests;

    const auto wait_start = std::chrono::steady_clock::now();
    const bool acquired = m_impl->cv.wait_until(lock, deadline, [this] {
        return m_impl->shutdown || !m_impl->available.empty() ||
               (m_impl->active_count + m_impl->available.size() < m_impl->config.max_connections);
    });

    const auto wait_end = std::chrono::steady_clock::now();
    --m_impl->pending_requests;

    const auto wait_duration_us =
        std::chrono::duration_cast<std::chrono::microseconds>(wait_end - wait_start).count();
    m_impl->wait_time_us += static_cast<std::uint64_t>(wait_duration_us);

    auto current_max = m_impl->max_wait_time_us.load(std::memory_order_relaxed);
    while (static_cast<std::uint64_t>(wait_duration_us) > current_max &&
           !m_impl->max_wait_time_us.compare_exchange_weak(
               current_max, static_cast<std::uint64_t>(wait_duration_us),
               std::memory_order_relaxed)) {
    }

    if (!acquired) {
        return std::unexpected(SearchConnectionError("Timed out waiting for connection"));
    }

    if (m_impl->shutdown) {
        return std::unexpected(SearchConnectionError("Connection pool has been shut down"));
    }

    if (!m_impl->available.empty()) {
        auto client = std::move(m_impl->available.front());
        m_impl->available.pop();
        ++m_impl->active_count;
        ++m_impl->acquired;

        const auto end_time = std::chrono::steady_clock::now();
        m_impl->acquisition_time_us +=
            static_cast<std::uint64_t>(std::chrono::duration_cast<std::chrono::microseconds>(
                end_time - start_time).count());

        return PooledOpenSearchClient{std::move(client), this};
    }

    // Create new connection
    ++m_impl->active_count;
    lock.unlock();

    SearchConfig search_config;
    search_config.host = m_impl->config.host;
    search_config.port = m_impl->config.port;
    search_config.timeout_seconds = static_cast<long>(m_impl->config.connection_timeout.count());

    try {
        auto client = std::make_unique<OpenSearchClient>(search_config);
        ++m_impl->created;
        ++m_impl->acquired;

        const auto end_time = std::chrono::steady_clock::now();
        m_impl->acquisition_time_us +=
            static_cast<std::uint64_t>(std::chrono::duration_cast<std::chrono::microseconds>(
                end_time - start_time).count());

        return PooledOpenSearchClient{std::move(client), this};
    } catch (const SearchConnectionError& e) {
        lock.lock();
        --m_impl->active_count;
        ++m_impl->acquisition_failures;
        m_impl->cv.notify_one();
        return std::unexpected(e);
    }
}

auto OpenSearchConnectionPool::try_acquire() -> std::optional<PooledOpenSearchClient> {
    std::unique_lock lock{m_impl->mutex};

    if (m_impl->shutdown || m_impl->available.empty()) {
        return std::nullopt;
    }

    auto client = std::move(m_impl->available.front());
    m_impl->available.pop();
    ++m_impl->active_count;
    ++m_impl->acquired;

    return PooledOpenSearchClient{std::move(client), this};
}

auto OpenSearchConnectionPool::active_connections() const noexcept -> std::size_t {
    std::unique_lock lock{m_impl->mutex};
    return m_impl->active_count;
}

auto OpenSearchConnectionPool::available_connections() const noexcept -> std::size_t {
    std::unique_lock lock{m_impl->mutex};
    return m_impl->available.size();
}

auto OpenSearchConnectionPool::max_connections() const noexcept -> std::size_t {
    return m_impl->config.max_connections;
}

auto OpenSearchConnectionPool::get_metrics() const noexcept -> PoolMetrics {
    std::unique_lock lock{m_impl->mutex};
    return PoolMetrics{
        .connections_acquired = m_impl->acquired,
        .connections_released = m_impl->released,
        .connections_created = m_impl->created,
        .connections_destroyed = m_impl->destroyed,
        .connections_idle_expired = m_impl->idle_expired,
        .below_min_count = m_impl->below_min_count,
        .acquisition_time_us = m_impl->acquisition_time_us,
        .wait_time_us = m_impl->wait_time_us,
        .max_wait_time_us = m_impl->max_wait_time_us.load(std::memory_order_relaxed),
        .acquisition_failures = m_impl->acquisition_failures,
    };
}

auto OpenSearchConnectionPool::get_pool_status() const noexcept -> PoolStatus {
    std::unique_lock lock{m_impl->mutex};
    return PoolStatus{
        .current_size = m_impl->active_count + m_impl->available.size(),
        .max_size = m_impl->config.max_connections,
        .idle_connections = m_impl->available.size(),
        .active_connections = m_impl->active_count,
        .pending_requests = m_impl->pending_requests,
    };
}

void OpenSearchConnectionPool::shutdown() {
    std::unique_lock lock{m_impl->mutex};
    if (m_impl->shutdown) {
        return;
    }

    m_impl->shutdown = true;
    m_impl->cv.notify_all();

    while (!m_impl->available.empty()) {
        m_impl->available.pop();
        ++m_impl->destroyed;
    }

    spdlog::info("OpenSearch connection pool shut down: created={}, destroyed={}",
                 m_impl->created, m_impl->destroyed);
}

void OpenSearchConnectionPool::return_connection(std::unique_ptr<OpenSearchClient> client) {
    std::unique_lock lock{m_impl->mutex};

    --m_impl->active_count;
    ++m_impl->released;

    if (m_impl->shutdown) {
        ++m_impl->destroyed;
        return;
    }

    m_impl->available.push(std::move(client));
    m_impl->cv.notify_one();
}

} // namespace muscovite_harbor::search

