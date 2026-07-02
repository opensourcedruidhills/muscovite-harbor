#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace intermodal_transfer {

/// Unified DBA struct for TruckVisit.
struct TruckVisit {
    boost::uuids::uuid id{};
    TruckPlate truck_plate{};
    std::string carrier_name{};
    boost::uuids::uuid slot_id{};
    muscovite::dba::Timestamp arrived_at{};
    muscovite::dba::Timestamp departed_at{};

    /// Construct from a database row.
    static auto from_row(const pqxx::row& row) -> TruckVisit {
        return TruckVisit{
            .id = row[0].as<std::string>(),
            .truck_plate = row[1].as<std::string>(),
            .carrier_name = row[2].as<std::string>(),
            .slot_id = row[3].as<std::string>(),
            .arrived_at = row[4].as<std::string>(),
            .departed_at = row[5].as<std::string>(),
        };
    }

    /// Try to construct; returns nullopt on missing required field.
    static auto try_from(const pqxx::row& row) -> std::optional<TruckVisit> {
        if (row[0].is_null()) return std::nullopt;
        if (row[1].is_null()) return std::nullopt;
        if (row[2].is_null()) return std::nullopt;
        if (row[3].is_null()) return std::nullopt;
        return from_row(row);
    }
};

} // namespace intermodal_transfer
