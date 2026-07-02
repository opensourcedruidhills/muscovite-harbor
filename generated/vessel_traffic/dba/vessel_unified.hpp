#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace vessel_traffic {

/// Unified DBA struct for Vessel.
struct Vessel {
    boost::uuids::uuid id{};
    IMONumber imo_number{};
    MMSI mmsi{};
    CallSign call_sign{};
    std::string name{};
    std::string vessel_type{};
    std::string flag_state{};
    bool is_active{};

    /// Construct from a database row.
    static auto from_row(const pqxx::row& row) -> Vessel {
        return Vessel{
            .id = row[0].as<std::string>(),
            .imo_number = row[1].as<std::string>(),
            .mmsi = row[2].as<std::string>(),
            .call_sign = row[3].as<std::string>(),
            .name = row[4].as<std::string>(),
            .vessel_type = row[5].as<std::string>(),
            .flag_state = row[6].as<std::string>(),
            .is_active = row[7].as<std::string>(),
        };
    }

    /// Try to construct; returns nullopt on missing required field.
    static auto try_from(const pqxx::row& row) -> std::optional<Vessel> {
        if (row[0].is_null()) return std::nullopt;
        if (row[1].is_null()) return std::nullopt;
        if (row[2].is_null()) return std::nullopt;
        if (row[3].is_null()) return std::nullopt;
        if (row[4].is_null()) return std::nullopt;
        if (row[5].is_null()) return std::nullopt;
        if (row[6].is_null()) return std::nullopt;
        if (row[7].is_null()) return std::nullopt;
        return from_row(row);
    }
};

} // namespace vessel_traffic
