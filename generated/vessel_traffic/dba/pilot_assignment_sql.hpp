#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace vessel_traffic {

// SQL constants for table: pilot_assignments
inline constexpr std::string_view kSelectAll =
    "SELECT id, voyage_id, pilot_name, pilot_zone, boarding_time, disembark_time FROM pilot_assignments";

inline constexpr std::string_view kSelectById =
    "SELECT id, voyage_id, pilot_name, pilot_zone, boarding_time, disembark_time FROM pilot_assignments WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO pilot_assignments (id, voyage_id, pilot_name, pilot_zone, boarding_time, disembark_time) VALUES ($1, $2, $3, $4, $5, $6)";

inline constexpr std::string_view kUpdate =
    "UPDATE pilot_assignments SET voyage_id = $2, pilot_name = $3, pilot_zone = $4, boarding_time = $5, disembark_time = $6 WHERE id = $1";

inline constexpr std::string_view kDelete =
    "DELETE FROM pilot_assignments WHERE id = $1";

} // namespace vessel_traffic
