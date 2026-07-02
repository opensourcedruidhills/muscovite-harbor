// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "policies.hpp"
#include <future>

namespace vessel_traffic {

auto AutoDispatchPilotPolicyHandler::matches(const VesselAnnounced& event) const -> bool {
    // WHY: #1476 — compiled from DSL policy condition
    (void)event;
    return eta < NOW() + INTERVAL '6 hours';
}

auto AutoDispatchPilotPolicyHandler::execute(const VesselAnnounced& event) const -> PolicyResult {
    if (matches(event)) {
    auto command = DispatchPilot{event};
    if (!command_dispatcher_ || !command_dispatcher_->dispatch(command)) {
        return PolicyResult::ActionFailed;
    }
    }
    return PolicyResult::Success;
}

} // namespace vessel_traffic
