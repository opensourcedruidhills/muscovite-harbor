#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace cargo_operations {

// SQL constants for table: yard_slots
inline constexpr std::string_view kSelectAll =
    "SELECT id, id, code, max_weight_kg, max_tier, has_power, is_occupied FROM yard_slots";

inline constexpr std::string_view kSelectById =
    "SELECT id, id, code, max_weight_kg, max_tier, has_power, is_occupied FROM yard_slots WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO yard_slots (id, id, code, max_weight_kg, max_tier, has_power, is_occupied) VALUES ($1, $2, $3, $4, $5, $6, $7)";

inline constexpr std::string_view kUpdate =
    "UPDATE yard_slots SET id = $2, code = $3, max_weight_kg = $4, max_tier = $5, has_power = $6, is_occupied = $7 WHERE id = $8";

inline constexpr std::string_view kDelete =
    "DELETE FROM yard_slots WHERE id = $1";

} // namespace cargo_operations
