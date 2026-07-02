#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace vessel_traffic {

/// Unified DBA struct for Berth.
struct Berth {
    boost::uuids::uuid id{};
    BerthCode code{};
    std::string name{};
    muscovite::dba::Decimal max_loa_metres{};
    muscovite::dba::Decimal max_draft_metres{};
    muscovite::dba::Decimal max_beam_metres{};
    bool has_crane_access{};
    bool has_reefer_plugs{};
    bool is_active{};

    /// Construct from a database row.
    static auto from_row(const pqxx::row& row) -> Berth {
        return Berth{
            .id = row[0].as<std::string>(),
            .code = row[1].as<std::string>(),
            .name = row[2].as<std::string>(),
            .max_loa_metres = row[3].as<std::string>(),
            .max_draft_metres = row[4].as<std::string>(),
            .max_beam_metres = row[5].as<std::string>(),
            .has_crane_access = row[6].as<std::string>(),
            .has_reefer_plugs = row[7].as<std::string>(),
            .is_active = row[8].as<std::string>(),
        };
    }

    /// Try to construct; returns nullopt on missing required field.
    static auto try_from(const pqxx::row& row) -> std::optional<Berth> {
        if (row[0].is_null()) return std::nullopt;
        if (row[1].is_null()) return std::nullopt;
        if (row[2].is_null()) return std::nullopt;
        if (row[3].is_null()) return std::nullopt;
        if (row[4].is_null()) return std::nullopt;
        if (row[5].is_null()) return std::nullopt;
        if (row[6].is_null()) return std::nullopt;
        if (row[7].is_null()) return std::nullopt;
        if (row[8].is_null()) return std::nullopt;
        return from_row(row);
    }
};

} // namespace vessel_traffic
