#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace security {

// SQL constants for table: context_privileges
inline constexpr std::string_view kSelectAll =
    "SELECT id, context_name, group_id, privilege FROM context_privileges";

inline constexpr std::string_view kSelectById =
    "SELECT id, context_name, group_id, privilege FROM context_privileges WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO context_privileges (id, context_name, group_id, privilege) VALUES ($1, $2, $3, $4)";

inline constexpr std::string_view kUpdate =
    "UPDATE context_privileges SET context_name = $2, group_id = $3, privilege = $4 WHERE id = $1";

inline constexpr std::string_view kDelete =
    "DELETE FROM context_privileges WHERE id = $1";

} // namespace security
