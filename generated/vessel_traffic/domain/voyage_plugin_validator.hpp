#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

// MUSCOVITE:SIDECAR:UNMODIFIED — remove this line when editing this file

#include "voyage.hpp"
#include <muscovite/validation/validation_errors.hpp>

namespace vessel_traffic {

/// Tier 3 plugin validator (sidecar): user-owned validation rules for Voyage.
/// Generated once, then user-owned. Remove the SIDECAR sentinel to edit.
class VoyagePluginValidator {
public:
    /// Validate user-defined rules. Returns accumulated error messages.
    [[nodiscard]] static auto validate(const Voyage& entity) -> muscovite::validation::ValidationErrors {
        (void)entity;
        auto errors = muscovite::validation::ValidationErrors{};
        return errors; // Add custom validation rules here
    }
};

} // namespace vessel_traffic
