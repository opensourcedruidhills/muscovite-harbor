#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace security {

// SQL constants for table: access_control_entrys
inline constexpr std::string_view kSelectAll =
    "SELECT id, principal, resource, permission, effect FROM access_control_entrys";

inline constexpr std::string_view kSelectById =
    "SELECT id, principal, resource, permission, effect FROM access_control_entrys WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO access_control_entrys (id, principal, resource, permission, effect) VALUES ($1, $2, $3, $4, $5)";

inline constexpr std::string_view kUpdate =
    "UPDATE access_control_entrys SET principal = $2, resource = $3, permission = $4, effect = $5 WHERE id = $6";

inline constexpr std::string_view kDelete =
    "DELETE FROM access_control_entrys WHERE id = $1";

} // namespace security
