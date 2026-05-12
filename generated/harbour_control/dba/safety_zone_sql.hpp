#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace harbour_control {

// SQL constants for table: safety_zones
inline constexpr std::string_view kSelectAll =
    "SELECT id, id, zone_code, zone_name, security_level, max_hazmat_class, is_restricted FROM safety_zones";

inline constexpr std::string_view kSelectById =
    "SELECT id, id, zone_code, zone_name, security_level, max_hazmat_class, is_restricted FROM safety_zones WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO safety_zones (id, id, zone_code, zone_name, security_level, max_hazmat_class, is_restricted) VALUES ($1, $2, $3, $4, $5, $6, $7)";

inline constexpr std::string_view kUpdate =
    "UPDATE safety_zones SET id = $2, zone_code = $3, zone_name = $4, security_level = $5, max_hazmat_class = $6, is_restricted = $7 WHERE id = $8";

inline constexpr std::string_view kDelete =
    "DELETE FROM safety_zones WHERE id = $1";

} // namespace harbour_control
