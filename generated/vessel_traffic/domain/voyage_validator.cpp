// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "voyage_validator.hpp"

namespace vessel_traffic {

auto VoyageValidator::check_vessel_exists(const Voyage& entity) -> bool {
    return vessel_id IS NOT NULL;
}

auto VoyageValidator::check_voyage_announced(const Voyage& entity) -> bool {
    return status = 'ANNOUNCED';
}

auto VoyageValidator::check_berth_available(const Voyage& entity) -> bool {
    return NOT EXISTS (SELECT 1 FROM voyage WHERE berth_id = berth_id AND status NOT IN ('DEPARTED'));
}

} // namespace vessel_traffic
