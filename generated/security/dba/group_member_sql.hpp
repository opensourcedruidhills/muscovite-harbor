#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace security {

// SQL constants for table: group_members
inline constexpr std::string_view kSelectAll =
    "SELECT id, group_id, user_id FROM group_members";

inline constexpr std::string_view kSelectById =
    "SELECT id, group_id, user_id FROM group_members WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO group_members (id, group_id, user_id) VALUES ($1, $2, $3)";

inline constexpr std::string_view kUpdate =
    "UPDATE group_members SET group_id = $2, user_id = $3 WHERE id = $1";

inline constexpr std::string_view kDelete =
    "DELETE FROM group_members WHERE id = $1";

} // namespace security
