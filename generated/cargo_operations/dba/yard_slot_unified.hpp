#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace cargo_operations {

/// Unified DBA struct for YardSlot.
struct YardSlot {
    boost::uuids::uuid id{};
    YardSlotCode code{};
    muscovite::dba::Decimal max_weight_kg{};
    std::int32_t max_tier{};
    bool has_power{};
    bool is_occupied{};

    /// Construct from a database row.
    static auto from_row(const pqxx::row& row) -> YardSlot {
        return YardSlot{
            .id = row[0].as<std::string>(),
            .code = row[1].as<std::string>(),
            .max_weight_kg = row[2].as<std::string>(),
            .max_tier = row[3].as<std::string>(),
            .has_power = row[4].as<std::string>(),
            .is_occupied = row[5].as<std::string>(),
        };
    }

    /// Try to construct; returns nullopt on missing required field.
    static auto try_from(const pqxx::row& row) -> std::optional<YardSlot> {
        if (row[0].is_null()) return std::nullopt;
        if (row[1].is_null()) return std::nullopt;
        if (row[2].is_null()) return std::nullopt;
        if (row[3].is_null()) return std::nullopt;
        if (row[4].is_null()) return std::nullopt;
        if (row[5].is_null()) return std::nullopt;
        return from_row(row);
    }
};

} // namespace cargo_operations
