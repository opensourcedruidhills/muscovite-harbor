#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "passenger.hpp"
#include <string>
#include <vector>

namespace passenger_terminal {

/// Tier 2 validator: cross-field invariants for Passenger.
/// No cross-field constraints — validate() is a no-op.
class PassengerValidator {
public:
    /// Validate cross-field invariants. Returns accumulated error messages.
    [[nodiscard]] static auto validate(const Passenger& entity) -> std::vector<std::string> {
        (void)entity;
        return {};
    }
};

} // namespace passenger_terminal
