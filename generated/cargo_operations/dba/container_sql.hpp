#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace cargo_operations {

// SQL constants for table: containers
inline constexpr std::string_view kSelectAll =
    "SELECT id, container_number, size_category, hazmat_class, voyage_id, yard_slot_id, status FROM containers";

inline constexpr std::string_view kSelectById =
    "SELECT id, container_number, size_category, hazmat_class, voyage_id, yard_slot_id, status FROM containers WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO containers (id, container_number, size_category, hazmat_class, voyage_id, yard_slot_id, status) VALUES ($1, $2, $3, $4, $5, $6, $7)";

inline constexpr std::string_view kUpdate =
    "UPDATE containers SET container_number = $2, size_category = $3, hazmat_class = $4, voyage_id = $5, yard_slot_id = $6, status = $7 WHERE id = $1";

inline constexpr std::string_view kDelete =
    "DELETE FROM containers WHERE id = $1";

} // namespace cargo_operations
