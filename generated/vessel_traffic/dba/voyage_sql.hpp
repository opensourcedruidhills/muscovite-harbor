#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace vessel_traffic {

// SQL constants for table: voyages
inline constexpr std::string_view kSelectAll =
    "SELECT id, id, vessel_id, berth_id, voyage_number, eta, ata, etd, atd, cargo_category, status FROM voyages";

inline constexpr std::string_view kSelectById =
    "SELECT id, id, vessel_id, berth_id, voyage_number, eta, ata, etd, atd, cargo_category, status FROM voyages WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO voyages (id, id, vessel_id, berth_id, voyage_number, eta, ata, etd, atd, cargo_category, status) VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11)";

inline constexpr std::string_view kUpdate =
    "UPDATE voyages SET id = $2, vessel_id = $3, berth_id = $4, voyage_number = $5, eta = $6, ata = $7, etd = $8, atd = $9, cargo_category = $10, status = $11 WHERE id = $12";

inline constexpr std::string_view kDelete =
    "DELETE FROM voyages WHERE id = $1";

} // namespace vessel_traffic
