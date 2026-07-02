#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace passenger_terminal {

// SQL constants for table: passengers
inline constexpr std::string_view kSelectAll =
    "SELECT id, booking_ref, passenger_type, voyage_id, status FROM passengers";

inline constexpr std::string_view kSelectById =
    "SELECT id, booking_ref, passenger_type, voyage_id, status FROM passengers WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO passengers (id, booking_ref, passenger_type, voyage_id, status) VALUES ($1, $2, $3, $4, $5)";

inline constexpr std::string_view kUpdate =
    "UPDATE passengers SET booking_ref = $2, passenger_type = $3, voyage_id = $4, status = $5 WHERE id = $1";

inline constexpr std::string_view kDelete =
    "DELETE FROM passengers WHERE id = $1";

} // namespace passenger_terminal
