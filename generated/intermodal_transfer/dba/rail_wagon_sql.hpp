#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace intermodal_transfer {

// SQL constants for table: rail_wagons
inline constexpr std::string_view kSelectAll =
    "SELECT id, wagon_number, max_weight_kg, slot_id FROM rail_wagons";

inline constexpr std::string_view kSelectById =
    "SELECT id, wagon_number, max_weight_kg, slot_id FROM rail_wagons WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO rail_wagons (id, wagon_number, max_weight_kg, slot_id) VALUES ($1, $2, $3, $4)";

inline constexpr std::string_view kUpdate =
    "UPDATE rail_wagons SET wagon_number = $2, max_weight_kg = $3, slot_id = $4 WHERE id = $1";

inline constexpr std::string_view kDelete =
    "DELETE FROM rail_wagons WHERE id = $1";

} // namespace intermodal_transfer
