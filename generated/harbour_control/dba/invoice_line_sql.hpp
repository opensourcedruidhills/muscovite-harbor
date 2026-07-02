#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string_view>

namespace harbour_control {

// SQL constants for table: invoice_lines
inline constexpr std::string_view kSelectAll =
    "SELECT id, vessel_id, service_type, amount, currency, issued_at FROM invoice_lines";

inline constexpr std::string_view kSelectById =
    "SELECT id, vessel_id, service_type, amount, currency, issued_at FROM invoice_lines WHERE id = $1";

inline constexpr std::string_view kInsert =
    "INSERT INTO invoice_lines (id, vessel_id, service_type, amount, currency, issued_at) VALUES ($1, $2, $3, $4, $5, $6)";

inline constexpr std::string_view kUpdate =
    "UPDATE invoice_lines SET vessel_id = $2, service_type = $3, amount = $4, currency = $5, issued_at = $6 WHERE id = $1";

inline constexpr std::string_view kDelete =
    "DELETE FROM invoice_lines WHERE id = $1";

} // namespace harbour_control
