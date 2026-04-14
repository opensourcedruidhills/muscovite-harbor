#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

// MUSCOVITE:SIDECAR:UNMODIFIED — remove this line when editing this file

#include "load_plan.hpp"
#include <string>
#include <vector>

namespace cargo_operations {

/// Tier 3 plugin validator (sidecar): user-owned validation rules for LoadPlan.
/// Generated once, then user-owned. Remove the SIDECAR sentinel to edit.
class LoadPlanPluginValidator {
public:
    /// Validate user-defined rules. Returns accumulated error messages.
    [[nodiscard]] static auto validate(const LoadPlan& entity) -> std::vector<std::string> {
        (void)entity;
        return {}; // Add custom validation rules here
    }
};

} // namespace cargo_operations
