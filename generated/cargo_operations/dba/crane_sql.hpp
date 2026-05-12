#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace cargo_operations {

// SQL constants for table: cranes
inline constexpr std::string_view kSelectAll =
    "SELECT id, id, name, crane_type, max_lift_kg, is_active FROM cranes";

inline constexpr std::string_view kSelectById =
    "SELECT id, id, name, crane_type, max_lift_kg, is_active FROM cranes WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO cranes (id, id, name, crane_type, max_lift_kg, is_active) VALUES ($1, $2, $3, $4, $5, $6)";

inline constexpr std::string_view kUpdate =
    "UPDATE cranes SET id = $2, name = $3, crane_type = $4, max_lift_kg = $5, is_active = $6 WHERE id = $7";

inline constexpr std::string_view kDelete =
    "DELETE FROM cranes WHERE id = $1";

} // namespace cargo_operations
