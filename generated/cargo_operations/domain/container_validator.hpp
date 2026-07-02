#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "container.hpp"
#include <string>
#include <muscovite/validation/validation_errors.hpp>

namespace cargo_operations {

/// Tier 2 validator: cross-field invariants for Container.
/// No cross-field constraints — validate() is a no-op.
class ContainerValidator {
public:
    /// Validate cross-field invariants. Returns accumulated error messages.
    [[nodiscard]] static auto validate(const Container& entity) -> muscovite::validation::ValidationErrors {
        (void)entity;
        auto errors = muscovite::validation::ValidationErrors{};
        return errors;
    }

    /// REQUIRES: slot_empty
    [[nodiscard]] static auto check_slot_empty(const Container& entity) -> bool;
    /// REQUIRES: weight_ok
    [[nodiscard]] static auto check_weight_ok(const Container& entity) -> bool;
    /// REQUIRES: is_top
    [[nodiscard]] static auto check_is_top(const Container& entity) -> bool;
};

} // namespace cargo_operations
