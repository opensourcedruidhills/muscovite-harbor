#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <chrono>
#include <cstdint>
#include <string>

#include <muscovite/dba/infrastructure_state_machine.hpp>

namespace cargo_operations {

/// Pluggable IMO hazmat segregation rule engine
/// Circuit breaker for Container.
/// Inherits thread-safe state machine with mutex, timeout-based
/// Open->HalfOpen transition, and configurable backoff from
/// muscovite::dba::InfrastructureStateMachineBase.
class HazmatSegregationValidatorCircuitBreaker final : public muscovite::dba::InfrastructureStateMachineBase<muscovite::dba::LinearBackoffPolicy> {
public:
    explicit HazmatSegregationValidatorCircuitBreaker(int failure_threshold = 5)
        : InfrastructureStateMachineBase{failure_threshold} {}
};

} // namespace cargo_operations
