#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "voyage.hpp"
#include <string>
#include <muscovite/validation/validation_errors.hpp>

namespace vessel_traffic {

/// Tier 2 validator: cross-field invariants for Voyage.
/// No cross-field constraints — validate() is a no-op.
class VoyageValidator {
public:
    /// Validate cross-field invariants. Returns accumulated error messages.
    [[nodiscard]] static auto validate(const Voyage& entity) -> muscovite::validation::ValidationErrors {
        (void)entity;
        auto errors = muscovite::validation::ValidationErrors{};
        return errors;
    }

    /// REQUIRES: vessel_exists
    [[nodiscard]] static auto check_vessel_exists(const Voyage& entity) -> bool;
    /// REQUIRES: voyage_announced
    [[nodiscard]] static auto check_voyage_announced(const Voyage& entity) -> bool;
    /// REQUIRES: berth_available
    [[nodiscard]] static auto check_berth_available(const Voyage& entity) -> bool;
};

} // namespace vessel_traffic
