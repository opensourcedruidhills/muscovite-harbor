// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "policies.hpp"
#include <future>

namespace cargo_operations {

auto ReeferTempAlertPolicyHandler::matches(const ReeferAlarm& event) const -> bool {
    // WHY: #1476 — compiled from DSL policy condition
    (void)event;
    return current_temp_c > target_temp_c + 5 OR current_temp_c < target_temp_c - 5;
}

auto ReeferTempAlertPolicyHandler::execute(const ReeferAlarm& event) const -> PolicyResult {
    if (matches(event)) {
    auto notification = Notification{.type = "OpsTeam", .payload = event};
    if (!notifier_ || !notifier_->send(notification)) {
        return PolicyResult::ActionFailed;
    }
    }
    return PolicyResult::Success;
}

} // namespace cargo_operations
