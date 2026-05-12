#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace security {

// SQL constants for table: audit_log_entrys
inline constexpr std::string_view kSelectAll =
    "SELECT id, timestamp, actor, action, resource, details FROM audit_log_entrys";

inline constexpr std::string_view kSelectById =
    "SELECT id, timestamp, actor, action, resource, details FROM audit_log_entrys WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO audit_log_entrys (id, timestamp, actor, action, resource, details) VALUES ($1, $2, $3, $4, $5, $6)";

inline constexpr std::string_view kUpdate =
    "UPDATE audit_log_entrys SET timestamp = $2, actor = $3, action = $4, resource = $5, details = $6 WHERE id = $7";

inline constexpr std::string_view kDelete =
    "DELETE FROM audit_log_entrys WHERE id = $1";

} // namespace security
