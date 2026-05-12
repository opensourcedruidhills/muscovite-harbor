#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace spatial {

// SQL constants for table: regions
inline constexpr std::string_view kSelectAll =
    "SELECT id, name, boundary, center FROM regions";

inline constexpr std::string_view kSelectById =
    "SELECT id, name, boundary, center FROM regions WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO regions (id, name, boundary, center) VALUES ($1, $2, $3, $4)";

inline constexpr std::string_view kUpdate =
    "UPDATE regions SET name = $2, boundary = $3, center = $4 WHERE id = $5";

inline constexpr std::string_view kDelete =
    "DELETE FROM regions WHERE id = $1";

} // namespace spatial
