#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <chrono>
#include <cstdint>
#include <functional>
#include <optional>
#include <string>

namespace cargo_operations {

/// Circuit breaker states.
enum class CircuitState { Closed, Open, HalfOpen };

/// Backoff policy for circuit breaker retry.
struct BackoffPolicy {
    std::chrono::milliseconds base_delay{500};
    std::chrono::milliseconds max_delay{30000};
    double jitter_percent{10.0};
};

/// Pluggable IMO hazmat segregation rule engine
/// Circuit breaker for Container.
class HazmatSegregationValidatorCircuitBreaker {
public:
    explicit HazmatSegregationValidatorCircuitBreaker(BackoffPolicy policy = {})
        : policy_{policy} {}

    /// Attempt to execute the protected operation.
    template<typename F>
    auto execute(F&& op) -> decltype(op()) {
        if (state_ == CircuitState::Open) {
            on_blocked();
            throw std::runtime_error("Circuit breaker is open for HazmatSegregationValidator");
        }
        try {
            auto result = op();
            on_success();
            return result;
        } catch (...) {
            on_failure();
            throw;
        }
    }

    [[nodiscard]] auto state() const -> CircuitState { return state_; }
    [[nodiscard]] auto failure_count() const -> std::int32_t { return failure_count_; }

    /// Override in derived class to customize actions.
    virtual auto on_success() -> void { state_ = CircuitState::Closed; failure_count_ = 0; }
    virtual auto on_failure() -> void;
    virtual auto on_blocked() -> void {}
    virtual auto on_half_open() -> void { state_ = CircuitState::HalfOpen; }

    virtual ~HazmatSegregationValidatorCircuitBreaker() = default;

protected:
    CircuitState state_{CircuitState::Closed};
    std::int32_t failure_count_{0};
    std::int32_t failure_threshold_{5};
    BackoffPolicy policy_;
};

} // namespace cargo_operations
