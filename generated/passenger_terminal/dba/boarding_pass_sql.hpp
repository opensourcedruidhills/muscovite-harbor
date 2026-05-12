#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace passenger_terminal {

// SQL constants for table: boarding_passs
inline constexpr std::string_view kSelectAll =
    "SELECT id, id, passenger_id, gate_id, boarding_group, seat_number, issued_at, scanned_at FROM boarding_passs";

inline constexpr std::string_view kSelectById =
    "SELECT id, id, passenger_id, gate_id, boarding_group, seat_number, issued_at, scanned_at FROM boarding_passs WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO boarding_passs (id, id, passenger_id, gate_id, boarding_group, seat_number, issued_at, scanned_at) VALUES ($1, $2, $3, $4, $5, $6, $7, $8)";

inline constexpr std::string_view kUpdate =
    "UPDATE boarding_passs SET id = $2, passenger_id = $3, gate_id = $4, boarding_group = $5, seat_number = $6, issued_at = $7, scanned_at = $8 WHERE id = $9";

inline constexpr std::string_view kDelete =
    "DELETE FROM boarding_passs WHERE id = $1";

} // namespace passenger_terminal
