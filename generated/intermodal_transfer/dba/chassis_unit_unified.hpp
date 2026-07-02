#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace intermodal_transfer {

/// Unified DBA struct for ChassisUnit.
struct ChassisUnit {
    boost::uuids::uuid id{};
    std::string chassis_number{};
    std::string chassis_type{};
    bool is_available{};

    /// Construct from a database row.
    static auto from_row(const pqxx::row& row) -> ChassisUnit {
        return ChassisUnit{
            .id = row[0].as<std::string>(),
            .chassis_number = row[1].as<std::string>(),
            .chassis_type = row[2].as<std::string>(),
            .is_available = row[3].as<std::string>(),
        };
    }

    /// Try to construct; returns nullopt on missing required field.
    static auto try_from(const pqxx::row& row) -> std::optional<ChassisUnit> {
        if (row[0].is_null()) return std::nullopt;
        if (row[1].is_null()) return std::nullopt;
        if (row[2].is_null()) return std::nullopt;
        if (row[3].is_null()) return std::nullopt;
        return from_row(row);
    }
};

} // namespace intermodal_transfer
