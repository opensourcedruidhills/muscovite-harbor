#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace harbour_control {

// SQL constants for table: port_calls
inline constexpr std::string_view kSelectAll =
    "SELECT id, id, vessel_name, imo_number, berth_code, arrival_time, departure_time, container_count, hazmat_permits, total_billed FROM port_calls";

inline constexpr std::string_view kSelectById =
    "SELECT id, id, vessel_name, imo_number, berth_code, arrival_time, departure_time, container_count, hazmat_permits, total_billed FROM port_calls WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO port_calls (id, id, vessel_name, imo_number, berth_code, arrival_time, departure_time, container_count, hazmat_permits, total_billed) VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10)";

inline constexpr std::string_view kUpdate =
    "UPDATE port_calls SET id = $2, vessel_name = $3, imo_number = $4, berth_code = $5, arrival_time = $6, departure_time = $7, container_count = $8, hazmat_permits = $9, total_billed = $10 WHERE id = $11";

inline constexpr std::string_view kDelete =
    "DELETE FROM port_calls WHERE id = $1";

} // namespace harbour_control
