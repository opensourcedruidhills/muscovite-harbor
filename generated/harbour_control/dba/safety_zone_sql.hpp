#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace harbour_control {

// SQL constants for table: safety_zones
inline constexpr std::string_view kSelectAll =
    "SELECT id, zone_code, zone_name, security_level, max_hazmat_class, is_restricted FROM safety_zones";

inline constexpr std::string_view kSelectById =
    "SELECT id, zone_code, zone_name, security_level, max_hazmat_class, is_restricted FROM safety_zones WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO safety_zones (id, zone_code, zone_name, security_level, max_hazmat_class, is_restricted) VALUES ($1, $2, $3, $4, $5, $6)";

inline constexpr std::string_view kUpdate =
    "UPDATE safety_zones SET zone_code = $2, zone_name = $3, security_level = $4, max_hazmat_class = $5, is_restricted = $6 WHERE id = $1";

inline constexpr std::string_view kDelete =
    "DELETE FROM safety_zones WHERE id = $1";

} // namespace harbour_control
