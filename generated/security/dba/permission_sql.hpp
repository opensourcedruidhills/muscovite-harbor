#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace security {

// SQL constants for table: permissions
inline constexpr std::string_view kSelectAll =
    "SELECT id, name, resource, action FROM permissions";

inline constexpr std::string_view kSelectById =
    "SELECT id, name, resource, action FROM permissions WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO permissions (id, name, resource, action) VALUES ($1, $2, $3, $4)";

inline constexpr std::string_view kUpdate =
    "UPDATE permissions SET name = $2, resource = $3, action = $4 WHERE id = $5";

inline constexpr std::string_view kDelete =
    "DELETE FROM permissions WHERE id = $1";

} // namespace security
