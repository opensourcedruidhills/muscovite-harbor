#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace intermodal_transfer {

// SQL constants for table: transfer_slots
inline constexpr std::string_view kSelectAll =
    "SELECT id, reference, container_id, transport_mode, scheduled_at, status FROM transfer_slots";

inline constexpr std::string_view kSelectById =
    "SELECT id, reference, container_id, transport_mode, scheduled_at, status FROM transfer_slots WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO transfer_slots (id, reference, container_id, transport_mode, scheduled_at, status) VALUES ($1, $2, $3, $4, $5, $6)";

inline constexpr std::string_view kUpdate =
    "UPDATE transfer_slots SET reference = $2, container_id = $3, transport_mode = $4, scheduled_at = $5, status = $6 WHERE id = $1";

inline constexpr std::string_view kDelete =
    "DELETE FROM transfer_slots WHERE id = $1";

} // namespace intermodal_transfer
