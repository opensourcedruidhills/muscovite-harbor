#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace security {

// SQL constants for table: roles
inline constexpr std::string_view kSelectAll =
    "SELECT id, name, description, permissions FROM roles";

inline constexpr std::string_view kSelectById =
    "SELECT id, name, description, permissions FROM roles WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO roles (id, name, description, permissions) VALUES ($1, $2, $3, $4)";

inline constexpr std::string_view kUpdate =
    "UPDATE roles SET name = $2, description = $3, permissions = $4 WHERE id = $5";

inline constexpr std::string_view kDelete =
    "DELETE FROM roles WHERE id = $1";

} // namespace security
