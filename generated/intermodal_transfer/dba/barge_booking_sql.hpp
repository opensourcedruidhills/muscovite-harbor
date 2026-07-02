#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace intermodal_transfer {

// SQL constants for table: barge_bookings
inline constexpr std::string_view kSelectAll =
    "SELECT id, barge_name, capacity_teu, departure_at, status FROM barge_bookings";

inline constexpr std::string_view kSelectById =
    "SELECT id, barge_name, capacity_teu, departure_at, status FROM barge_bookings WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO barge_bookings (id, barge_name, capacity_teu, departure_at, status) VALUES ($1, $2, $3, $4, $5)";

inline constexpr std::string_view kUpdate =
    "UPDATE barge_bookings SET barge_name = $2, capacity_teu = $3, departure_at = $4, status = $5 WHERE id = $1";

inline constexpr std::string_view kDelete =
    "DELETE FROM barge_bookings WHERE id = $1";

} // namespace intermodal_transfer
