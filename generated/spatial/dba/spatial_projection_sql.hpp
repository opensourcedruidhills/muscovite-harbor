#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace spatial {

// SQL constants for table: spatial_projections
inline constexpr std::string_view kSelectAll =
    "SELECT id, name, srid, definition FROM spatial_projections";

inline constexpr std::string_view kSelectById =
    "SELECT id, name, srid, definition FROM spatial_projections WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO spatial_projections (id, name, srid, definition) VALUES ($1, $2, $3, $4)";

inline constexpr std::string_view kUpdate =
    "UPDATE spatial_projections SET name = $2, srid = $3, definition = $4 WHERE id = $5";

inline constexpr std::string_view kDelete =
    "DELETE FROM spatial_projections WHERE id = $1";

} // namespace spatial
