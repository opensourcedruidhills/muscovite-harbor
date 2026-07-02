#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace cargo_decomposition {

// SQL constants for table: pallets
inline constexpr std::string_view kSelectAll =
    "SELECT id, pallet_id, container_id, weight_kg, length_cm, width_cm, height_cm, hs_code FROM pallets";

inline constexpr std::string_view kSelectById =
    "SELECT id, pallet_id, container_id, weight_kg, length_cm, width_cm, height_cm, hs_code FROM pallets WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO pallets (id, pallet_id, container_id, weight_kg, length_cm, width_cm, height_cm, hs_code) VALUES ($1, $2, $3, $4, $5, $6, $7, $8)";

inline constexpr std::string_view kUpdate =
    "UPDATE pallets SET pallet_id = $2, container_id = $3, weight_kg = $4, length_cm = $5, width_cm = $6, height_cm = $7, hs_code = $8 WHERE id = $1";

inline constexpr std::string_view kDelete =
    "DELETE FROM pallets WHERE id = $1";

} // namespace cargo_decomposition
