#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <cstdint>
#include <string>

namespace vessel_traffic {

/// Result of a policy execution.
enum class PolicyResult {
    Success,
    ConditionNotMet,
    ActionFailed,
    Timeout,
    MaxRetriesExceeded,
};

/// Configuration for policy execution behavior.
struct PolicyOptions {
    std::int32_t max_retries{0};
    std::int32_t timeout_seconds{0};
    bool async{false};
};

/// Auto-dispatch pilot for imminent arrivals
/// Triggered by: VesselAnnounced
class AutoDispatchPilotPolicyHandler {
public:
    [[nodiscard]] auto matches(const VesselAnnounced& event) const -> bool;
    [[nodiscard]] auto execute(const VesselAnnounced& event) const -> PolicyResult;
    [[nodiscard]] auto name() const -> std::string { return "AutoDispatchPilot"; }

    [[nodiscard]] auto options() const -> PolicyOptions {
        return PolicyOptions{
            .max_retries = 3,
            .timeout_seconds = 15,
        };
    }
};

/// Policy registry — dispatches events to matching handlers.
class PolicyRegistry {
public:
    /// Dispatch an event to all matching policy handlers.
    template<typename Event>
    auto dispatch(const Event& event) const -> void;
};

} // namespace vessel_traffic
