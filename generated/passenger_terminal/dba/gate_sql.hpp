#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace passenger_terminal {

// SQL constants for table: gates
inline constexpr std::string_view kSelectAll =
    "SELECT id, code, name, capacity, status, voyage_id FROM gates";

inline constexpr std::string_view kSelectById =
    "SELECT id, code, name, capacity, status, voyage_id FROM gates WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO gates (id, code, name, capacity, status, voyage_id) VALUES ($1, $2, $3, $4, $5, $6)";

inline constexpr std::string_view kUpdate =
    "UPDATE gates SET code = $2, name = $3, capacity = $4, status = $5, voyage_id = $6 WHERE id = $1";

inline constexpr std::string_view kDelete =
    "DELETE FROM gates WHERE id = $1";

} // namespace passenger_terminal
