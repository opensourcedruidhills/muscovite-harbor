// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "specifications.hpp"

namespace vessel_traffic {

auto AvailableBerthsSpec::is_satisfied_by(const Berth& entity) const -> bool {
    (void)entity;
    return false; // No expression defined in DSL
}

auto VesselsByETASpec::is_satisfied_by(const Voyage& entity) const -> bool {
    (void)entity;
    return false; // No expression defined in DSL
}

} // namespace vessel_traffic
