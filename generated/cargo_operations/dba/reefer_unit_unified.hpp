#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace cargo_operations {

/// Unified DBA struct for ReeferUnit.
struct ReeferUnit {
    boost::uuids::uuid id{};
    boost::uuids::uuid container_id{};
    muscovite::dba::Decimal target_temp_c{};
    muscovite::dba::Decimal current_temp_c{};
    bool is_powered{};

    /// Construct from a database row.
    static auto from_row(const pqxx::row& row) -> ReeferUnit {
        return ReeferUnit{
            .id = row[0].as<std::string>(),
            .container_id = row[1].as<std::string>(),
            .target_temp_c = row[2].as<std::string>(),
            .current_temp_c = row[3].as<std::string>(),
            .is_powered = row[4].as<std::string>(),
        };
    }

    /// Try to construct; returns nullopt on missing required field.
    static auto try_from(const pqxx::row& row) -> std::optional<ReeferUnit> {
        if (row[0].is_null()) return std::nullopt;
        if (row[1].is_null()) return std::nullopt;
        if (row[2].is_null()) return std::nullopt;
        if (row[4].is_null()) return std::nullopt;
        return from_row(row);
    }
};

} // namespace cargo_operations
