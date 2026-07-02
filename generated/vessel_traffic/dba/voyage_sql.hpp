#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace vessel_traffic {

// SQL constants for table: voyages
inline constexpr std::string_view kSelectAll =
    "SELECT id, vessel_id, berth_id, voyage_number, eta, ata, etd, atd, cargo_category, status FROM voyages";

inline constexpr std::string_view kSelectById =
    "SELECT id, vessel_id, berth_id, voyage_number, eta, ata, etd, atd, cargo_category, status FROM voyages WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO voyages (id, vessel_id, berth_id, voyage_number, eta, ata, etd, atd, cargo_category, status) VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10)";

inline constexpr std::string_view kUpdate =
    "UPDATE voyages SET vessel_id = $2, berth_id = $3, voyage_number = $4, eta = $5, ata = $6, etd = $7, atd = $8, cargo_category = $9, status = $10 WHERE id = $1";

inline constexpr std::string_view kDelete =
    "DELETE FROM voyages WHERE id = $1";

} // namespace vessel_traffic
