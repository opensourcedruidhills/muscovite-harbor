#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace passenger_terminal {

/// Unified DBA struct for Gate.
struct Gate {
    boost::uuids::uuid id{};
    GateCode code{};
    std::string name{};
    std::int32_t capacity{};
    std::string status{};
    boost::uuids::uuid voyage_id{};

    /// Construct from a database row.
    static auto from_row(const pqxx::row& row) -> Gate {
        return Gate{
            .id = row[0].as<std::string>(),
            .code = row[1].as<std::string>(),
            .name = row[2].as<std::string>(),
            .capacity = row[3].as<std::string>(),
            .status = row[4].as<std::string>(),
            .voyage_id = row[5].as<std::string>(),
        };
    }

    /// Try to construct; returns nullopt on missing required field.
    static auto try_from(const pqxx::row& row) -> std::optional<Gate> {
        if (row[0].is_null()) return std::nullopt;
        if (row[1].is_null()) return std::nullopt;
        if (row[2].is_null()) return std::nullopt;
        if (row[3].is_null()) return std::nullopt;
        if (row[4].is_null()) return std::nullopt;
        return from_row(row);
    }
};

} // namespace passenger_terminal
