// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann

#pragma once

/// @file connection_pool.hpp
/// @brief Thread-safe OpenSearch connection pool
/// @see ADR 20260120 — domain services as aggregate boundary
/// @note Mirrors the DBA connection pool pattern with configurable pool size,
///       timeout, and health checks.

#include <chrono>
#include <expected>
#include <memory>
#include <optional>
#include <string>
#include <cstddef>

#include <muscovite/search/opensearch_client.hpp>
#include <muscovite/search/search_error.hpp>

namespace muscovite_harbor::search {

/// Connection pool error codes
enum class PoolError {
    ConnectionFailed,  ///< Failed to establish connection
    PoolExhausted,     ///< No connections available
    Timeout,           ///< Timed out waiting for connection
    InvalidConfig,     ///< Invalid pool configuration
    AlreadyShutdown    ///< Pool has been shut down
};

/// Connection pool configuration
/// @note min_connections is a startup warm-up hint, not a runtime floor.
///       The pool creates min_connections eagerly during create(), but
///       try_acquire()/acquire() may return connections even when the pool
///       drops below min_connections due to idle expiry or health check failure.
struct PoolConfig {
    std::string host;                          ///< OpenSearch host
    std::uint16_t port{9200};                  ///< OpenSearch port
    std::size_t min_connections{2};            ///< Startup warm-up hint (not a runtime guarantee)
    std::size_t max_connections{10};           ///< Maximum pool size
    std::chrono::seconds connection_timeout{30};    ///< Timeout for new connections
    std::chrono::seconds idle_timeout{300};         ///< Close idle connections after
    std::chrono::seconds health_check_interval{60}; ///< Health check frequency
    bool validate_on_borrow{true};             ///< Validate connection before use
};

/// Snapshot of pool metrics at a point in time.
/// Counters are lifetime totals since pool creation.
struct PoolMetrics {
    std::uint64_t connections_acquired{0};
    std::uint64_t connections_released{0};
    std::uint64_t connections_created{0};
    std::uint64_t connections_destroyed{0};
    std::uint64_t connections_idle_expired{0}; ///< connections discarded due to idle timeout
    std::uint64_t below_min_count{0};          ///< acquire() calls where pool was below min_connections
    std::uint64_t acquisition_time_us{0};   ///< total microseconds spent in acquire()
    std::uint64_t wait_time_us{0};          ///< total microseconds waiting for a free slot
    std::uint64_t max_wait_time_us{0};      ///< longest single wait in microseconds
    std::uint64_t acquisition_failures{0};  ///< acquire() calls that returned an error
};

/// Point-in-time snapshot of pool slot utilization.
struct PoolStatus {
    std::size_t current_size{0};       ///< total connections in pool (idle + active)
    std::size_t max_size{0};           ///< pool capacity (from PoolConfig)
    std::size_t idle_connections{0};   ///< ready for use
    std::size_t active_connections{0}; ///< currently checked out
    std::size_t pending_requests{0};   ///< threads waiting for a connection
};

class OpenSearchConnectionPool;

/// RAII wrapper for a pooled OpenSearch client connection.
/// Returns connection to pool on destruction.
class PooledOpenSearchClient {
public:
    PooledOpenSearchClient(PooledOpenSearchClient&&) noexcept;
    PooledOpenSearchClient& operator=(PooledOpenSearchClient&&) noexcept;
    ~PooledOpenSearchClient();

    // Non-copyable
    PooledOpenSearchClient(const PooledOpenSearchClient&) = delete;
    PooledOpenSearchClient& operator=(const PooledOpenSearchClient&) = delete;

    /// Get the underlying OpenSearch client
    [[nodiscard]] auto get() -> OpenSearchClient&;
    [[nodiscard]] auto get() const -> const OpenSearchClient&;

    /// Arrow operator for direct access
    [[nodiscard]] auto operator->() -> OpenSearchClient*;
    [[nodiscard]] auto operator->() const -> const OpenSearchClient*;

private:
    friend class OpenSearchConnectionPool;
    PooledOpenSearchClient(std::unique_ptr<OpenSearchClient> client,
                          OpenSearchConnectionPool* pool);

    std::unique_ptr<OpenSearchClient> m_client;
    OpenSearchConnectionPool* m_pool;
};

/// Thread-safe OpenSearch connection pool.
///
/// Usage:
/// ```cpp
/// auto config = PoolConfig{.host = "localhost", .port = 9200, .max_connections = 10};
/// auto pool = OpenSearchConnectionPool::create(config).value();
/// {
///     auto client = pool.acquire().value();
///     auto result = client->search({"my_index"}, query_json);
/// } // Connection returns to pool
/// ```
class OpenSearchConnectionPool {
public:
    /// Create a new connection pool.
    /// @param config Pool configuration
    /// @return Pool on success, Error on failure
    [[nodiscard]] static auto create(PoolConfig config)
        -> std::expected<OpenSearchConnectionPool, SearchError>;

    OpenSearchConnectionPool(OpenSearchConnectionPool&&) noexcept;
    OpenSearchConnectionPool& operator=(OpenSearchConnectionPool&&) noexcept;
    ~OpenSearchConnectionPool();

    // Non-copyable
    OpenSearchConnectionPool(const OpenSearchConnectionPool&) = delete;
    OpenSearchConnectionPool& operator=(const OpenSearchConnectionPool&) = delete;

    /// Acquire a connection from the pool.
    /// Blocks until a connection is available.
    /// @return Connection on success, Error on failure
    [[nodiscard]] auto acquire() -> std::expected<PooledOpenSearchClient, SearchError>;

    /// Acquire a connection with timeout.
    /// @param timeout Maximum time to wait
    /// @return Connection on success, Error on failure/timeout
    [[nodiscard]] auto acquire(std::chrono::milliseconds timeout)
        -> std::expected<PooledOpenSearchClient, SearchError>;

    /// Try to acquire a connection without blocking.
    /// @return Connection if immediately available, nullopt otherwise
    [[nodiscard]] auto try_acquire() -> std::optional<PooledOpenSearchClient>;

    /// Get number of active (checked out) connections
    [[nodiscard]] auto active_connections() const noexcept -> std::size_t;

    /// Get number of available (idle) connections
    [[nodiscard]] auto available_connections() const noexcept -> std::size_t;

    /// Get maximum pool size
    [[nodiscard]] auto max_connections() const noexcept -> std::size_t;

    /// Returns a copy of the lifetime metrics snapshot. Thread-safe.
    [[nodiscard]] auto get_metrics() const noexcept -> PoolMetrics;

    /// Returns current pool slot utilization. Thread-safe.
    [[nodiscard]] auto get_pool_status() const noexcept -> PoolStatus;

    /// Shutdown the pool, closing all connections.
    void shutdown();

private:
    friend class PooledOpenSearchClient;
    OpenSearchConnectionPool();

    void return_connection(std::unique_ptr<OpenSearchClient> client);

    struct Impl;
    std::unique_ptr<Impl> m_impl;
};

} // namespace muscovite_harbor::search

