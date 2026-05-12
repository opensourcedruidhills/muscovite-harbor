#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace cargo_decomposition {

// SQL constants for table: break_bulk_items
inline constexpr std::string_view kSelectAll =
    "SELECT id, id, container_id, item_type, weight_kg, requires_crane FROM break_bulk_items";

inline constexpr std::string_view kSelectById =
    "SELECT id, id, container_id, item_type, weight_kg, requires_crane FROM break_bulk_items WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO break_bulk_items (id, id, container_id, item_type, weight_kg, requires_crane) VALUES ($1, $2, $3, $4, $5, $6)";

inline constexpr std::string_view kUpdate =
    "UPDATE break_bulk_items SET id = $2, container_id = $3, item_type = $4, weight_kg = $5, requires_crane = $6 WHERE id = $7";

inline constexpr std::string_view kDelete =
    "DELETE FROM break_bulk_items WHERE id = $1";

} // namespace cargo_decomposition
