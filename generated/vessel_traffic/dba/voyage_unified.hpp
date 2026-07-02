#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace vessel_traffic {

/// Unified DBA struct for Voyage.
struct Voyage {
    boost::uuids::uuid id{};
    boost::uuids::uuid vessel_id{};
    boost::uuids::uuid berth_id{};
    std::string voyage_number{};
    muscovite::dba::Timestamp eta{};
    muscovite::dba::Timestamp ata{};
    muscovite::dba::Timestamp etd{};
    muscovite::dba::Timestamp atd{};
    std::string cargo_category{};
    std::string status{};

    /// Construct from a database row.
    static auto from_row(const pqxx::row& row) -> Voyage {
        return Voyage{
            .id = row[0].as<std::string>(),
            .vessel_id = row[1].as<std::string>(),
            .berth_id = row[2].as<std::string>(),
            .voyage_number = row[3].as<std::string>(),
            .eta = row[4].as<std::string>(),
            .ata = row[5].as<std::string>(),
            .etd = row[6].as<std::string>(),
            .atd = row[7].as<std::string>(),
            .cargo_category = row[8].as<std::string>(),
            .status = row[9].as<std::string>(),
        };
    }

    /// Try to construct; returns nullopt on missing required field.
    static auto try_from(const pqxx::row& row) -> std::optional<Voyage> {
        if (row[0].is_null()) return std::nullopt;
        if (row[1].is_null()) return std::nullopt;
        if (row[3].is_null()) return std::nullopt;
        if (row[4].is_null()) return std::nullopt;
        if (row[8].is_null()) return std::nullopt;
        if (row[9].is_null()) return std::nullopt;
        return from_row(row);
    }
};

} // namespace vessel_traffic
