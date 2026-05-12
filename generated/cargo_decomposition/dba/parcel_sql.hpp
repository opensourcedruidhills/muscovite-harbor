#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace cargo_decomposition {

// SQL constants for table: parcels
inline constexpr std::string_view kSelectAll =
    "SELECT id, id, tracking_number, pallet_id, weight_kg, hs_code, description FROM parcels";

inline constexpr std::string_view kSelectById =
    "SELECT id, id, tracking_number, pallet_id, weight_kg, hs_code, description FROM parcels WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO parcels (id, id, tracking_number, pallet_id, weight_kg, hs_code, description) VALUES ($1, $2, $3, $4, $5, $6, $7)";

inline constexpr std::string_view kUpdate =
    "UPDATE parcels SET id = $2, tracking_number = $3, pallet_id = $4, weight_kg = $5, hs_code = $6, description = $7 WHERE id = $8";

inline constexpr std::string_view kDelete =
    "DELETE FROM parcels WHERE id = $1";

} // namespace cargo_decomposition
