#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

// MUSCOVITE:SIDECAR:UNMODIFIED — remove this line when editing this file

#include "container.hpp"
#include <string>
#include <vector>

namespace cargo_operations {

/// Tier 3 plugin validator (sidecar): user-owned validation rules for Container.
/// Generated once, then user-owned. Remove the SIDECAR sentinel to edit.
class ContainerPluginValidator {
public:
    /// Validate user-defined rules. Returns accumulated error messages.
    [[nodiscard]] static auto validate(const Container& entity) -> std::vector<std::string> {
        (void)entity;
        return {}; // Add custom validation rules here
    }
};

} // namespace cargo_operations
