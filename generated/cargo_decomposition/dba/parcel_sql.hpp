#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace cargo_decomposition {

// SQL constants for table: parcels
inline constexpr std::string_view kSelectAll =
    "SELECT id, tracking_number, pallet_id, weight_kg, hs_code, description FROM parcels";

inline constexpr std::string_view kSelectById =
    "SELECT id, tracking_number, pallet_id, weight_kg, hs_code, description FROM parcels WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO parcels (id, tracking_number, pallet_id, weight_kg, hs_code, description) VALUES ($1, $2, $3, $4, $5, $6)";

inline constexpr std::string_view kUpdate =
    "UPDATE parcels SET tracking_number = $2, pallet_id = $3, weight_kg = $4, hs_code = $5, description = $6 WHERE id = $1";

inline constexpr std::string_view kDelete =
    "DELETE FROM parcels WHERE id = $1";

} // namespace cargo_decomposition
