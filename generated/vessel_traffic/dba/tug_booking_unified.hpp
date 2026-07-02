#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace vessel_traffic {

/// Unified DBA struct for TugBooking.
struct TugBooking {
    boost::uuids::uuid id{};
    boost::uuids::uuid voyage_id{};
    std::string tug_name{};
    muscovite::dba::Decimal bollard_pull_t{};
    bool is_confirmed{};

    /// Construct from a database row.
    static auto from_row(const pqxx::row& row) -> TugBooking {
        return TugBooking{
            .id = row[0].as<std::string>(),
            .voyage_id = row[1].as<std::string>(),
            .tug_name = row[2].as<std::string>(),
            .bollard_pull_t = row[3].as<std::string>(),
            .is_confirmed = row[4].as<std::string>(),
        };
    }

    /// Try to construct; returns nullopt on missing required field.
    static auto try_from(const pqxx::row& row) -> std::optional<TugBooking> {
        if (row[0].is_null()) return std::nullopt;
        if (row[1].is_null()) return std::nullopt;
        if (row[2].is_null()) return std::nullopt;
        if (row[3].is_null()) return std::nullopt;
        if (row[4].is_null()) return std::nullopt;
        return from_row(row);
    }
};

} // namespace vessel_traffic
