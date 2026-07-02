// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "policies.hpp"
#include <future>

namespace harbour_control {

auto LogHazmatApprovalPolicyHandler::matches(const HazmatPermitApproved& event) const -> bool {
    // WHY: #1476 — compiled from DSL policy condition
    (void)event;
    return permit_number IS NOT NULL;
}

auto LogHazmatApprovalPolicyHandler::execute(const HazmatPermitApproved& event) const -> PolicyResult {
    if (matches(event)) {
    auto command = AuditHazmatPermit{event};
    if (!command_dispatcher_ || !command_dispatcher_->dispatch(command)) {
        return PolicyResult::ActionFailed;
    }
    }
    return PolicyResult::Success;
}

} // namespace harbour_control
