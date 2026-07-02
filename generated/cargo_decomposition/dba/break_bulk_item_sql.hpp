#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace cargo_decomposition {

// SQL constants for table: break_bulk_items
inline constexpr std::string_view kSelectAll =
    "SELECT id, container_id, item_type, weight_kg, requires_crane FROM break_bulk_items";

inline constexpr std::string_view kSelectById =
    "SELECT id, container_id, item_type, weight_kg, requires_crane FROM break_bulk_items WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO break_bulk_items (id, container_id, item_type, weight_kg, requires_crane) VALUES ($1, $2, $3, $4, $5)";

inline constexpr std::string_view kUpdate =
    "UPDATE break_bulk_items SET container_id = $2, item_type = $3, weight_kg = $4, requires_crane = $5 WHERE id = $1";

inline constexpr std::string_view kDelete =
    "DELETE FROM break_bulk_items WHERE id = $1";

} // namespace cargo_decomposition
