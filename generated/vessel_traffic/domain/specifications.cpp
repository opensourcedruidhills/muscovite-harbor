// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "specifications.hpp"

namespace vessel_traffic {

auto AvailableBerthsSpec::is_satisfied_by(const Berth& entity) const -> bool {
    // expression: (entity.get_max_draft_metres() >= entity.get_min_draft())
    return (entity.get_max_draft_metres() >= entity.get_min_draft());
}

auto VesselsByETASpec::is_satisfied_by(const Voyage& entity) const -> bool {
    // expression: entity.get_eta()
    return entity.get_eta();
}

} // namespace vessel_traffic
