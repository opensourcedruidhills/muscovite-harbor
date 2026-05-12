#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <cstdint>
#include <string>

namespace cargo_decomposition {

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

/// Notify logistics ops when a parcel is dispatched for last-mile delivery
/// Triggered by: ParcelDispatched
class TrackParcelDispatchPolicyHandler {
public:
    [[nodiscard]] auto matches(const ParcelDispatched& event) const -> bool;
    [[nodiscard]] auto execute(const ParcelDispatched& event) const -> PolicyResult;
    [[nodiscard]] auto name() const -> std::string { return "TrackParcelDispatch"; }

    [[nodiscard]] auto options() const -> PolicyOptions {
        return PolicyOptions{
            .max_retries = 2,
            .timeout_seconds = 5,
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

} // namespace cargo_decomposition
