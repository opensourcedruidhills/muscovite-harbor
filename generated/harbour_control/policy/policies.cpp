// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "policies.hpp"

namespace harbour_control {

auto LogHazmatApprovalPolicyHandler::matches(const HazmatPermitApproved& event) const -> bool {
    // WHY: #1476 — compiled from DSL policy condition
    (void)event;
    return ;
}

auto LogHazmatApprovalPolicyHandler::execute(const HazmatPermitApproved& event) const -> PolicyResult {
    (void)event;
    // Invoke command: AuditHazmatPermit
    return PolicyResult::Success;
}

} // namespace harbour_control
