// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "policies.hpp"

namespace cargo_operations {

auto ReeferTempAlertPolicyHandler::matches(const ReeferAlarm& event) const -> bool {
    // WHY: #1476 — compiled from DSL policy condition
    (void)event;
    return ;
}

auto ReeferTempAlertPolicyHandler::execute(const ReeferAlarm& event) const -> PolicyResult {
    (void)event;
    // Send notification: OpsTeam
    return PolicyResult::Success;
}

} // namespace cargo_operations
