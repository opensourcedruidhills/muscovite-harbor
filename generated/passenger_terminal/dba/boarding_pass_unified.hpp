#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace passenger_terminal {

/// Unified DBA struct for BoardingPass.
struct BoardingPass {
    boost::uuids::uuid id{};
    boost::uuids::uuid passenger_id{};
    boost::uuids::uuid gate_id{};
    std::string boarding_group{};
    std::string seat_number{};
    muscovite::dba::Timestamp issued_at{};
    muscovite::dba::Timestamp scanned_at{};

    /// Construct from a database row.
    static auto from_row(const pqxx::row& row) -> BoardingPass {
        return BoardingPass{
            .id = row[0].as<std::string>(),
            .passenger_id = row[1].as<std::string>(),
            .gate_id = row[2].as<std::string>(),
            .boarding_group = row[3].as<std::string>(),
            .seat_number = row[4].as<std::string>(),
            .issued_at = row[5].as<std::string>(),
            .scanned_at = row[6].as<std::string>(),
        };
    }

    /// Try to construct; returns nullopt on missing required field.
    static auto try_from(const pqxx::row& row) -> std::optional<BoardingPass> {
        if (row[0].is_null()) return std::nullopt;
        if (row[1].is_null()) return std::nullopt;
        if (row[3].is_null()) return std::nullopt;
        if (row[5].is_null()) return std::nullopt;
        return from_row(row);
    }
};

} // namespace passenger_terminal
