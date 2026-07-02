#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace vessel_traffic {

// SQL constants for table: berths
inline constexpr std::string_view kSelectAll =
    "SELECT id, code, name, max_loa_metres, max_draft_metres, max_beam_metres, has_crane_access, has_reefer_plugs, is_active FROM berths";

inline constexpr std::string_view kSelectById =
    "SELECT id, code, name, max_loa_metres, max_draft_metres, max_beam_metres, has_crane_access, has_reefer_plugs, is_active FROM berths WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO berths (id, code, name, max_loa_metres, max_draft_metres, max_beam_metres, has_crane_access, has_reefer_plugs, is_active) VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9)";

inline constexpr std::string_view kUpdate =
    "UPDATE berths SET code = $2, name = $3, max_loa_metres = $4, max_draft_metres = $5, max_beam_metres = $6, has_crane_access = $7, has_reefer_plugs = $8, is_active = $9 WHERE id = $1";

inline constexpr std::string_view kDelete =
    "DELETE FROM berths WHERE id = $1";

} // namespace vessel_traffic
