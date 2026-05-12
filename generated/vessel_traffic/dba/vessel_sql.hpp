#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace vessel_traffic {

// SQL constants for table: vessels
inline constexpr std::string_view kSelectAll =
    "SELECT id, id, imo_number, mmsi, call_sign, name, vessel_type, flag_state, is_active FROM vessels";

inline constexpr std::string_view kSelectById =
    "SELECT id, id, imo_number, mmsi, call_sign, name, vessel_type, flag_state, is_active FROM vessels WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO vessels (id, id, imo_number, mmsi, call_sign, name, vessel_type, flag_state, is_active) VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9)";

inline constexpr std::string_view kUpdate =
    "UPDATE vessels SET id = $2, imo_number = $3, mmsi = $4, call_sign = $5, name = $6, vessel_type = $7, flag_state = $8, is_active = $9 WHERE id = $10";

inline constexpr std::string_view kDelete =
    "DELETE FROM vessels WHERE id = $1";

} // namespace vessel_traffic
