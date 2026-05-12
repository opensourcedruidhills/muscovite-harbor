#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace cargo_decomposition {

// SQL constants for table: delivery_units
inline constexpr std::string_view kSelectAll =
    "SELECT id, id, tracking_number, destination, carrier, dispatched_at FROM delivery_units";

inline constexpr std::string_view kSelectById =
    "SELECT id, id, tracking_number, destination, carrier, dispatched_at FROM delivery_units WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO delivery_units (id, id, tracking_number, destination, carrier, dispatched_at) VALUES ($1, $2, $3, $4, $5, $6)";

inline constexpr std::string_view kUpdate =
    "UPDATE delivery_units SET id = $2, tracking_number = $3, destination = $4, carrier = $5, dispatched_at = $6 WHERE id = $7";

inline constexpr std::string_view kDelete =
    "DELETE FROM delivery_units WHERE id = $1";

} // namespace cargo_decomposition
