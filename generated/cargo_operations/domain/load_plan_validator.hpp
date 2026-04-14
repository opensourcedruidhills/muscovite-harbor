#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "load_plan.hpp"
#include <string>
#include <vector>

namespace cargo_operations {

/// Tier 2 validator: cross-field invariants for LoadPlan.
/// No cross-field constraints — validate() is a no-op.
class LoadPlanValidator {
public:
    /// Validate cross-field invariants. Returns accumulated error messages.
    [[nodiscard]] static auto validate(const LoadPlan& entity) -> std::vector<std::string> {
        (void)entity;
        return {};
    }
};

} // namespace cargo_operations
