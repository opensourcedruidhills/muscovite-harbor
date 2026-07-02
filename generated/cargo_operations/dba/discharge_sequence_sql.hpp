#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace cargo_operations {

// SQL constants for table: discharge_sequences
inline constexpr std::string_view kSelectAll =
    "SELECT id, load_plan_id, container_id, sequence_order, crane_id FROM discharge_sequences";

inline constexpr std::string_view kSelectById =
    "SELECT id, load_plan_id, container_id, sequence_order, crane_id FROM discharge_sequences WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO discharge_sequences (id, load_plan_id, container_id, sequence_order, crane_id) VALUES ($1, $2, $3, $4, $5)";

inline constexpr std::string_view kUpdate =
    "UPDATE discharge_sequences SET load_plan_id = $2, container_id = $3, sequence_order = $4, crane_id = $5 WHERE id = $1";

inline constexpr std::string_view kDelete =
    "DELETE FROM discharge_sequences WHERE id = $1";

} // namespace cargo_operations
