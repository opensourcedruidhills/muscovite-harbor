#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace security {

// SQL constants for table: users
inline constexpr std::string_view kSelectAll =
    "SELECT id, username, email, password_hash, is_active FROM users";

inline constexpr std::string_view kSelectById =
    "SELECT id, username, email, password_hash, is_active FROM users WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO users (id, username, email, password_hash, is_active) VALUES ($1, $2, $3, $4, $5)";

inline constexpr std::string_view kUpdate =
    "UPDATE users SET username = $2, email = $3, password_hash = $4, is_active = $5 WHERE id = $6";

inline constexpr std::string_view kDelete =
    "DELETE FROM users WHERE id = $1";

} // namespace security
