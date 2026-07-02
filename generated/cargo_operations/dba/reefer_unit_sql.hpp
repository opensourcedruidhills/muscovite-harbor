#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace cargo_operations {

// SQL constants for table: reefer_units
inline constexpr std::string_view kSelectAll =
    "SELECT id, container_id, target_temp_c, current_temp_c, is_powered FROM reefer_units";

inline constexpr std::string_view kSelectById =
    "SELECT id, container_id, target_temp_c, current_temp_c, is_powered FROM reefer_units WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO reefer_units (id, container_id, target_temp_c, current_temp_c, is_powered) VALUES ($1, $2, $3, $4, $5)";

inline constexpr std::string_view kUpdate =
    "UPDATE reefer_units SET container_id = $2, target_temp_c = $3, current_temp_c = $4, is_powered = $5 WHERE id = $1";

inline constexpr std::string_view kDelete =
    "DELETE FROM reefer_units WHERE id = $1";

} // namespace cargo_operations
