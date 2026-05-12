#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace intermodal_transfer {

// SQL constants for table: chassis_units
inline constexpr std::string_view kSelectAll =
    "SELECT id, id, chassis_number, chassis_type, is_available FROM chassis_units";

inline constexpr std::string_view kSelectById =
    "SELECT id, id, chassis_number, chassis_type, is_available FROM chassis_units WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO chassis_units (id, id, chassis_number, chassis_type, is_available) VALUES ($1, $2, $3, $4, $5)";

inline constexpr std::string_view kUpdate =
    "UPDATE chassis_units SET id = $2, chassis_number = $3, chassis_type = $4, is_available = $5 WHERE id = $6";

inline constexpr std::string_view kDelete =
    "DELETE FROM chassis_units WHERE id = $1";

} // namespace intermodal_transfer
