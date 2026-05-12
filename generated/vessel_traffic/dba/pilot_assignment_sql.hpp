#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace vessel_traffic {

// SQL constants for table: pilot_assignments
inline constexpr std::string_view kSelectAll =
    "SELECT id, id, voyage_id, pilot_name, pilot_zone, boarding_time, disembark_time FROM pilot_assignments";

inline constexpr std::string_view kSelectById =
    "SELECT id, id, voyage_id, pilot_name, pilot_zone, boarding_time, disembark_time FROM pilot_assignments WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO pilot_assignments (id, id, voyage_id, pilot_name, pilot_zone, boarding_time, disembark_time) VALUES ($1, $2, $3, $4, $5, $6, $7)";

inline constexpr std::string_view kUpdate =
    "UPDATE pilot_assignments SET id = $2, voyage_id = $3, pilot_name = $4, pilot_zone = $5, boarding_time = $6, disembark_time = $7 WHERE id = $8";

inline constexpr std::string_view kDelete =
    "DELETE FROM pilot_assignments WHERE id = $1";

} // namespace vessel_traffic
