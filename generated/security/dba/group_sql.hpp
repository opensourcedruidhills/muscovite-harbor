#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace security {

// SQL constants for table: groups
inline constexpr std::string_view kSelectAll =
    "SELECT id, name, description FROM groups";

inline constexpr std::string_view kSelectById =
    "SELECT id, name, description FROM groups WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO groups (id, name, description) VALUES ($1, $2, $3)";

inline constexpr std::string_view kUpdate =
    "UPDATE groups SET name = $2, description = $3 WHERE id = $1";

inline constexpr std::string_view kDelete =
    "DELETE FROM groups WHERE id = $1";

} // namespace security
