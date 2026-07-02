#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace harbour_control {

// SQL constants for table: port_calls
inline constexpr std::string_view kSelectAll =
    "SELECT id, vessel_name, imo_number, berth_code, arrival_time, departure_time, container_count, hazmat_permits, total_billed FROM port_calls";

inline constexpr std::string_view kSelectById =
    "SELECT id, vessel_name, imo_number, berth_code, arrival_time, departure_time, container_count, hazmat_permits, total_billed FROM port_calls WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO port_calls (id, vessel_name, imo_number, berth_code, arrival_time, departure_time, container_count, hazmat_permits, total_billed) VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9)";

inline constexpr std::string_view kUpdate =
    "UPDATE port_calls SET vessel_name = $2, imo_number = $3, berth_code = $4, arrival_time = $5, departure_time = $6, container_count = $7, hazmat_permits = $8, total_billed = $9 WHERE id = $1";

inline constexpr std::string_view kDelete =
    "DELETE FROM port_calls WHERE id = $1";

} // namespace harbour_control
