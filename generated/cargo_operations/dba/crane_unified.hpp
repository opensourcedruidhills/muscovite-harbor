#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace cargo_operations {

/// Unified DBA struct for Crane.
struct Crane {
    boost::uuids::uuid id{};
    std::string name{};
    std::string crane_type{};
    muscovite::dba::Decimal max_lift_kg{};
    bool is_active{};

    /// Construct from a database row.
    static auto from_row(const pqxx::row& row) -> Crane {
        return Crane{
            .id = row[0].as<std::string>(),
            .name = row[1].as<std::string>(),
            .crane_type = row[2].as<std::string>(),
            .max_lift_kg = row[3].as<std::string>(),
            .is_active = row[4].as<std::string>(),
        };
    }

    /// Try to construct; returns nullopt on missing required field.
    static auto try_from(const pqxx::row& row) -> std::optional<Crane> {
        if (row[0].is_null()) return std::nullopt;
        if (row[1].is_null()) return std::nullopt;
        if (row[2].is_null()) return std::nullopt;
        if (row[3].is_null()) return std::nullopt;
        if (row[4].is_null()) return std::nullopt;
        return from_row(row);
    }
};

} // namespace cargo_operations
