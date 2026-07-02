#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace cargo_decomposition {

// SQL constants for table: delivery_units
inline constexpr std::string_view kSelectAll =
    "SELECT id, tracking_number, destination, carrier, dispatched_at FROM delivery_units";

inline constexpr std::string_view kSelectById =
    "SELECT id, tracking_number, destination, carrier, dispatched_at FROM delivery_units WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO delivery_units (id, tracking_number, destination, carrier, dispatched_at) VALUES ($1, $2, $3, $4, $5)";

inline constexpr std::string_view kUpdate =
    "UPDATE delivery_units SET tracking_number = $2, destination = $3, carrier = $4, dispatched_at = $5 WHERE id = $1";

inline constexpr std::string_view kDelete =
    "DELETE FROM delivery_units WHERE id = $1";

} // namespace cargo_decomposition
