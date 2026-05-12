#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace vessel_traffic {

// SQL constants for table: tide_windows
inline constexpr std::string_view kSelectAll =
    "SELECT id, id, berth_id, tide_height_metres, available_draft FROM tide_windows";

inline constexpr std::string_view kSelectById =
    "SELECT id, id, berth_id, tide_height_metres, available_draft FROM tide_windows WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO tide_windows (id, id, berth_id, tide_height_metres, available_draft) VALUES ($1, $2, $3, $4, $5)";

inline constexpr std::string_view kUpdate =
    "UPDATE tide_windows SET id = $2, berth_id = $3, tide_height_metres = $4, available_draft = $5 WHERE id = $6";

inline constexpr std::string_view kDelete =
    "DELETE FROM tide_windows WHERE id = $1";

} // namespace vessel_traffic
