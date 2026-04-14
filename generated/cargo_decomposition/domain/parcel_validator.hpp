#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "parcel.hpp"
#include <string>
#include <vector>

namespace cargo_decomposition {

/// Tier 2 validator: cross-field invariants for Parcel.
/// No cross-field constraints — validate() is a no-op.
class ParcelValidator {
public:
    /// Validate cross-field invariants. Returns accumulated error messages.
    [[nodiscard]] static auto validate(const Parcel& entity) -> std::vector<std::string> {
        (void)entity;
        return {};
    }
};

} // namespace cargo_decomposition
