#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace harbour_control {

/// Unified DBA struct for PortCall.
struct PortCall {
    boost::uuids::uuid id{};
    std::string vessel_name{};
    std::string imo_number{};
    std::string berth_code{};
    muscovite::dba::Timestamp arrival_time{};
    muscovite::dba::Timestamp departure_time{};
    std::int32_t container_count{};
    std::int32_t hazmat_permits{};
    muscovite::dba::Decimal total_billed{};

    /// Construct from a database row.
    static auto from_row(const pqxx::row& row) -> PortCall {
        return PortCall{
            .id = row[0].as<std::string>(),
            .vessel_name = row[1].as<std::string>(),
            .imo_number = row[2].as<std::string>(),
            .berth_code = row[3].as<std::string>(),
            .arrival_time = row[4].as<std::string>(),
            .departure_time = row[5].as<std::string>(),
            .container_count = row[6].as<std::string>(),
            .hazmat_permits = row[7].as<std::string>(),
            .total_billed = row[8].as<std::string>(),
        };
    }

    /// Try to construct; returns nullopt on missing required field.
    static auto try_from(const pqxx::row& row) -> std::optional<PortCall> {
        if (row[0].is_null()) return std::nullopt;
        if (row[1].is_null()) return std::nullopt;
        if (row[2].is_null()) return std::nullopt;
        if (row[6].is_null()) return std::nullopt;
        if (row[7].is_null()) return std::nullopt;
        if (row[8].is_null()) return std::nullopt;
        return from_row(row);
    }
};

} // namespace harbour_control
