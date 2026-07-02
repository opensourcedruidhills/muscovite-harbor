// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "policies.hpp"
#include <future>

namespace cargo_decomposition {

auto TrackParcelDispatchPolicyHandler::matches(const ParcelDispatched& event) const -> bool {
    // WHY: #1476 — compiled from DSL policy condition
    (void)event;
    return carrier IS NOT NULL;
}

auto TrackParcelDispatchPolicyHandler::execute(const ParcelDispatched& event) const -> PolicyResult {
    if (matches(event)) {
    auto notification = Notification{.type = "LogisticsOps", .payload = event};
    if (!notifier_ || !notifier_->send(notification)) {
        return PolicyResult::ActionFailed;
    }
    }
    return PolicyResult::Success;
}

} // namespace cargo_decomposition
