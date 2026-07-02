#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

// MUSCOVITE:SIDECAR:UNMODIFIED — remove this line when editing this file

#include "transfer_slot.hpp"
#include <muscovite/validation/validation_errors.hpp>

namespace intermodal_transfer {

/// Tier 3 plugin validator (sidecar): user-owned validation rules for TransferSlot.
/// Generated once, then user-owned. Remove the SIDECAR sentinel to edit.
class TransferSlotPluginValidator {
public:
    /// Validate user-defined rules. Returns accumulated error messages.
    [[nodiscard]] static auto validate(const TransferSlot& entity) -> muscovite::validation::ValidationErrors {
        (void)entity;
        auto errors = muscovite::validation::ValidationErrors{};
        return errors; // Add custom validation rules here
    }
};

} // namespace intermodal_transfer
