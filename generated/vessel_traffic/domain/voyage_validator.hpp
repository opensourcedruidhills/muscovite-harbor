#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "voyage.hpp"
#include <string>
#include <vector>

namespace vessel_traffic {

/// Tier 2 validator: cross-field invariants for Voyage.
/// No cross-field constraints — validate() is a no-op.
class VoyageValidator {
public:
    /// Validate cross-field invariants. Returns accumulated error messages.
    [[nodiscard]] static auto validate(const Voyage& entity) -> std::vector<std::string> {
        (void)entity;
        return {};
    }
};

} // namespace vessel_traffic
