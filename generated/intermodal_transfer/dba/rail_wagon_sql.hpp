#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace intermodal_transfer {

// SQL constants for table: rail_wagons
inline constexpr std::string_view kSelectAll =
    "SELECT id, id, wagon_number, max_weight_kg, slot_id FROM rail_wagons";

inline constexpr std::string_view kSelectById =
    "SELECT id, id, wagon_number, max_weight_kg, slot_id FROM rail_wagons WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO rail_wagons (id, id, wagon_number, max_weight_kg, slot_id) VALUES ($1, $2, $3, $4, $5)";

inline constexpr std::string_view kUpdate =
    "UPDATE rail_wagons SET id = $2, wagon_number = $3, max_weight_kg = $4, slot_id = $5 WHERE id = $6";

inline constexpr std::string_view kDelete =
    "DELETE FROM rail_wagons WHERE id = $1";

} // namespace intermodal_transfer
