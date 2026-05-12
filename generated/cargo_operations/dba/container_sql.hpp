#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace cargo_operations {

// SQL constants for table: containers
inline constexpr std::string_view kSelectAll =
    "SELECT id, id, container_number, size_category, hazmat_class, voyage_id, yard_slot_id, status FROM containers";

inline constexpr std::string_view kSelectById =
    "SELECT id, id, container_number, size_category, hazmat_class, voyage_id, yard_slot_id, status FROM containers WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO containers (id, id, container_number, size_category, hazmat_class, voyage_id, yard_slot_id, status) VALUES ($1, $2, $3, $4, $5, $6, $7, $8)";

inline constexpr std::string_view kUpdate =
    "UPDATE containers SET id = $2, container_number = $3, size_category = $4, hazmat_class = $5, voyage_id = $6, yard_slot_id = $7, status = $8 WHERE id = $9";

inline constexpr std::string_view kDelete =
    "DELETE FROM containers WHERE id = $1";

} // namespace cargo_operations
