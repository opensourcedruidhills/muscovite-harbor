#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace harbour_control {

// SQL constants for table: invoice_lines
inline constexpr std::string_view kSelectAll =
    "SELECT id, id, vessel_id, service_type, amount, currency, issued_at FROM invoice_lines";

inline constexpr std::string_view kSelectById =
    "SELECT id, id, vessel_id, service_type, amount, currency, issued_at FROM invoice_lines WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO invoice_lines (id, id, vessel_id, service_type, amount, currency, issued_at) VALUES ($1, $2, $3, $4, $5, $6, $7)";

inline constexpr std::string_view kUpdate =
    "UPDATE invoice_lines SET id = $2, vessel_id = $3, service_type = $4, amount = $5, currency = $6, issued_at = $7 WHERE id = $8";

inline constexpr std::string_view kDelete =
    "DELETE FROM invoice_lines WHERE id = $1";

} // namespace harbour_control
