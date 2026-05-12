// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "policies.hpp"

namespace vessel_traffic {

auto AutoDispatchPilotPolicyHandler::matches(const VesselAnnounced& event) const -> bool {
    // WHY: #1476 — compiled from DSL policy condition
    (void)event;
    return ;
}

auto AutoDispatchPilotPolicyHandler::execute(const VesselAnnounced& event) const -> PolicyResult {
    (void)event;
    // Invoke command: DispatchPilot
    return PolicyResult::Success;
}

} // namespace vessel_traffic
