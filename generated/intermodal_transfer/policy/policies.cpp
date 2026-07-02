// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "policies.hpp"
#include <future>

namespace intermodal_transfer {

auto LogDeparturePolicyHandler::matches(const DepartureConfirmed& /*event*/) const -> bool {
    return true; // No condition defined — always matches
}

auto LogDeparturePolicyHandler::execute(const DepartureConfirmed& event) const -> PolicyResult {
    auto notification = Notification{.type = "LogisticsOps", .payload = event};
    if (!notifier_ || !notifier_->send(notification)) {
        return PolicyResult::ActionFailed;
    }
    return PolicyResult::Success;
}

} // namespace intermodal_transfer
