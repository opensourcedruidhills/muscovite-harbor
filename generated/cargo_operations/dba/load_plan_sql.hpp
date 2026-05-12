#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace cargo_operations {

// SQL constants for table: load_plans
inline constexpr std::string_view kSelectAll =
    "SELECT id, id, voyage_id, created_at, status FROM load_plans";

inline constexpr std::string_view kSelectById =
    "SELECT id, id, voyage_id, created_at, status FROM load_plans WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO load_plans (id, id, voyage_id, created_at, status) VALUES ($1, $2, $3, $4, $5)";

inline constexpr std::string_view kUpdate =
    "UPDATE load_plans SET id = $2, voyage_id = $3, created_at = $4, status = $5 WHERE id = $6";

inline constexpr std::string_view kDelete =
    "DELETE FROM load_plans WHERE id = $1";

} // namespace cargo_operations
