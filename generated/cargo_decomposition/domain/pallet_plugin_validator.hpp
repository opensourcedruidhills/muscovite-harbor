#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

// MUSCOVITE:SIDECAR:UNMODIFIED — remove this line when editing this file

#include "pallet.hpp"
#include <muscovite/validation/validation_errors.hpp>

namespace cargo_decomposition {

/// Tier 3 plugin validator (sidecar): user-owned validation rules for Pallet.
/// Generated once, then user-owned. Remove the SIDECAR sentinel to edit.
class PalletPluginValidator {
public:
    /// Validate user-defined rules. Returns accumulated error messages.
    [[nodiscard]] static auto validate(const Pallet& entity) -> muscovite::validation::ValidationErrors {
        (void)entity;
        auto errors = muscovite::validation::ValidationErrors{};
        return errors; // Add custom validation rules here
    }
};

} // namespace cargo_decomposition
