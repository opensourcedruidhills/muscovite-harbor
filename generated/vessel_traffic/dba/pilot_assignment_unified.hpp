#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace vessel_traffic {

/// Unified DBA struct for PilotAssignment.
struct PilotAssignment {
    boost::uuids::uuid id{};
    boost::uuids::uuid voyage_id{};
    std::string pilot_name{};
    std::string pilot_zone{};
    muscovite::dba::Timestamp boarding_time{};
    muscovite::dba::Timestamp disembark_time{};

    /// Construct from a database row.
    static auto from_row(const pqxx::row& row) -> PilotAssignment {
        return PilotAssignment{
            .id = row[0].as<std::string>(),
            .voyage_id = row[1].as<std::string>(),
            .pilot_name = row[2].as<std::string>(),
            .pilot_zone = row[3].as<std::string>(),
            .boarding_time = row[4].as<std::string>(),
            .disembark_time = row[5].as<std::string>(),
        };
    }

    /// Try to construct; returns nullopt on missing required field.
    static auto try_from(const pqxx::row& row) -> std::optional<PilotAssignment> {
        if (row[0].is_null()) return std::nullopt;
        if (row[1].is_null()) return std::nullopt;
        if (row[2].is_null()) return std::nullopt;
        if (row[3].is_null()) return std::nullopt;
        return from_row(row);
    }
};

} // namespace vessel_traffic
