#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace intermodal_transfer {

// SQL constants for table: chassis_units
inline constexpr std::string_view kSelectAll =
    "SELECT id, chassis_number, chassis_type, is_available FROM chassis_units";

inline constexpr std::string_view kSelectById =
    "SELECT id, chassis_number, chassis_type, is_available FROM chassis_units WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO chassis_units (id, chassis_number, chassis_type, is_available) VALUES ($1, $2, $3, $4)";

inline constexpr std::string_view kUpdate =
    "UPDATE chassis_units SET chassis_number = $2, chassis_type = $3, is_available = $4 WHERE id = $1";

inline constexpr std::string_view kDelete =
    "DELETE FROM chassis_units WHERE id = $1";

} // namespace intermodal_transfer
