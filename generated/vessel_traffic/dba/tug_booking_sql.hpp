#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace vessel_traffic {

// SQL constants for table: tug_bookings
inline constexpr std::string_view kSelectAll =
    "SELECT id, id, voyage_id, tug_name, bollard_pull_t, is_confirmed FROM tug_bookings";

inline constexpr std::string_view kSelectById =
    "SELECT id, id, voyage_id, tug_name, bollard_pull_t, is_confirmed FROM tug_bookings WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO tug_bookings (id, id, voyage_id, tug_name, bollard_pull_t, is_confirmed) VALUES ($1, $2, $3, $4, $5, $6)";

inline constexpr std::string_view kUpdate =
    "UPDATE tug_bookings SET id = $2, voyage_id = $3, tug_name = $4, bollard_pull_t = $5, is_confirmed = $6 WHERE id = $7";

inline constexpr std::string_view kDelete =
    "DELETE FROM tug_bookings WHERE id = $1";

} // namespace vessel_traffic
