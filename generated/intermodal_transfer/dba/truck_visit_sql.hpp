#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace intermodal_transfer {

// SQL constants for table: truck_visits
inline constexpr std::string_view kSelectAll =
    "SELECT id, id, truck_plate, carrier_name, slot_id, arrived_at, departed_at FROM truck_visits";

inline constexpr std::string_view kSelectById =
    "SELECT id, id, truck_plate, carrier_name, slot_id, arrived_at, departed_at FROM truck_visits WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO truck_visits (id, id, truck_plate, carrier_name, slot_id, arrived_at, departed_at) VALUES ($1, $2, $3, $4, $5, $6, $7)";

inline constexpr std::string_view kUpdate =
    "UPDATE truck_visits SET id = $2, truck_plate = $3, carrier_name = $4, slot_id = $5, arrived_at = $6, departed_at = $7 WHERE id = $8";

inline constexpr std::string_view kDelete =
    "DELETE FROM truck_visits WHERE id = $1";

} // namespace intermodal_transfer
