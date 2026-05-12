#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace security {

// SQL constants for table: user_roles
inline constexpr std::string_view kSelectAll =
    "SELECT id, user_id, role_id FROM user_roles";

inline constexpr std::string_view kSelectById =
    "SELECT id, user_id, role_id FROM user_roles WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO user_roles (id, user_id, role_id) VALUES ($1, $2, $3)";

inline constexpr std::string_view kUpdate =
    "UPDATE user_roles SET user_id = $2, role_id = $3 WHERE id = $4";

inline constexpr std::string_view kDelete =
    "DELETE FROM user_roles WHERE id = $1";

} // namespace security
