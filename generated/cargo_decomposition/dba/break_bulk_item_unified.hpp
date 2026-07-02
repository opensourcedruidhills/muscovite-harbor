#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace cargo_decomposition {

/// Unified DBA struct for BreakBulkItem.
struct BreakBulkItem {
    boost::uuids::uuid id{};
    boost::uuids::uuid container_id{};
    std::string item_type{};
    muscovite::dba::Decimal weight_kg{};
    bool requires_crane{};

    /// Construct from a database row.
    static auto from_row(const pqxx::row& row) -> BreakBulkItem {
        return BreakBulkItem{
            .id = row[0].as<std::string>(),
            .container_id = row[1].as<std::string>(),
            .item_type = row[2].as<std::string>(),
            .weight_kg = row[3].as<std::string>(),
            .requires_crane = row[4].as<std::string>(),
        };
    }

    /// Try to construct; returns nullopt on missing required field.
    static auto try_from(const pqxx::row& row) -> std::optional<BreakBulkItem> {
        if (row[0].is_null()) return std::nullopt;
        if (row[1].is_null()) return std::nullopt;
        if (row[2].is_null()) return std::nullopt;
        if (row[3].is_null()) return std::nullopt;
        if (row[4].is_null()) return std::nullopt;
        return from_row(row);
    }
};

} // namespace cargo_decomposition
