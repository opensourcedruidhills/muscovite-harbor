#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace harbour_control {

/// Unified DBA struct for SafetyZone.
struct SafetyZone {
    boost::uuids::uuid id{};
    ZoneCode zone_code{};
    std::string zone_name{};
    std::string security_level{};
    std::int32_t max_hazmat_class{};
    bool is_restricted{};

    /// Construct from a database row.
    static auto from_row(const pqxx::row& row) -> SafetyZone {
        return SafetyZone{
            .id = row[0].as<std::string>(),
            .zone_code = row[1].as<std::string>(),
            .zone_name = row[2].as<std::string>(),
            .security_level = row[3].as<std::string>(),
            .max_hazmat_class = row[4].as<std::string>(),
            .is_restricted = row[5].as<std::string>(),
        };
    }

    /// Try to construct; returns nullopt on missing required field.
    static auto try_from(const pqxx::row& row) -> std::optional<SafetyZone> {
        if (row[0].is_null()) return std::nullopt;
        if (row[1].is_null()) return std::nullopt;
        if (row[2].is_null()) return std::nullopt;
        if (row[3].is_null()) return std::nullopt;
        if (row[4].is_null()) return std::nullopt;
        if (row[5].is_null()) return std::nullopt;
        return from_row(row);
    }
};

} // namespace harbour_control
