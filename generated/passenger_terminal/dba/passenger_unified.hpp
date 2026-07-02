#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace passenger_terminal {

/// Unified DBA struct for Passenger.
struct Passenger {
    boost::uuids::uuid id{};
    BookingReference booking_ref{};
    std::string passenger_type{};
    boost::uuids::uuid voyage_id{};
    std::string status{};

    /// Construct from a database row.
    static auto from_row(const pqxx::row& row) -> Passenger {
        return Passenger{
            .id = row[0].as<std::string>(),
            .booking_ref = row[1].as<std::string>(),
            .passenger_type = row[2].as<std::string>(),
            .voyage_id = row[3].as<std::string>(),
            .status = row[4].as<std::string>(),
        };
    }

    /// Try to construct; returns nullopt on missing required field.
    static auto try_from(const pqxx::row& row) -> std::optional<Passenger> {
        if (row[0].is_null()) return std::nullopt;
        if (row[1].is_null()) return std::nullopt;
        if (row[2].is_null()) return std::nullopt;
        if (row[3].is_null()) return std::nullopt;
        if (row[4].is_null()) return std::nullopt;
        return from_row(row);
    }
};

} // namespace passenger_terminal
