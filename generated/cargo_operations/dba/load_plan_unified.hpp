#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace cargo_operations {

/// Unified DBA struct for LoadPlan.
struct LoadPlan {
    boost::uuids::uuid id{};
    boost::uuids::uuid voyage_id{};
    muscovite::dba::Timestamp created_at{};
    std::string status{};

    /// Construct from a database row.
    static auto from_row(const pqxx::row& row) -> LoadPlan {
        return LoadPlan{
            .id = row[0].as<std::string>(),
            .voyage_id = row[1].as<std::string>(),
            .created_at = row[2].as<std::string>(),
            .status = row[3].as<std::string>(),
        };
    }

    /// Try to construct; returns nullopt on missing required field.
    static auto try_from(const pqxx::row& row) -> std::optional<LoadPlan> {
        if (row[0].is_null()) return std::nullopt;
        if (row[1].is_null()) return std::nullopt;
        if (row[2].is_null()) return std::nullopt;
        if (row[3].is_null()) return std::nullopt;
        return from_row(row);
    }
};

} // namespace cargo_operations
