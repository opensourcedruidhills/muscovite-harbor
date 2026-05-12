#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace spatial {

// SQL constants for table: coordinates
inline constexpr std::string_view kSelectAll =
    "SELECT id, latitude, longitude, altitude, srid FROM coordinates";

inline constexpr std::string_view kSelectById =
    "SELECT id, latitude, longitude, altitude, srid FROM coordinates WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO coordinates (id, latitude, longitude, altitude, srid) VALUES ($1, $2, $3, $4, $5)";

inline constexpr std::string_view kUpdate =
    "UPDATE coordinates SET latitude = $2, longitude = $3, altitude = $4, srid = $5 WHERE id = $6";

inline constexpr std::string_view kDelete =
    "DELETE FROM coordinates WHERE id = $1";

} // namespace spatial
