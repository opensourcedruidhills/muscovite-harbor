#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace harbour_control {

// SQL constants for table: hazmat_permits
inline constexpr std::string_view kSelectAll =
    "SELECT id, permit_number, vessel_id, imo_class, quantity_kg, approved, valid_from, valid_until FROM hazmat_permits";

inline constexpr std::string_view kSelectById =
    "SELECT id, permit_number, vessel_id, imo_class, quantity_kg, approved, valid_from, valid_until FROM hazmat_permits WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO hazmat_permits (id, permit_number, vessel_id, imo_class, quantity_kg, approved, valid_from, valid_until) VALUES ($1, $2, $3, $4, $5, $6, $7, $8)";

inline constexpr std::string_view kUpdate =
    "UPDATE hazmat_permits SET permit_number = $2, vessel_id = $3, imo_class = $4, quantity_kg = $5, approved = $6, valid_from = $7, valid_until = $8 WHERE id = $1";

inline constexpr std::string_view kDelete =
    "DELETE FROM hazmat_permits WHERE id = $1";

} // namespace harbour_control
