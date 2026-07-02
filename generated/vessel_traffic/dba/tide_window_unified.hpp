#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace vessel_traffic {

/// Unified DBA struct for TideWindow.
struct TideWindow {
    boost::uuids::uuid id{};
    boost::uuids::uuid berth_id{};
    muscovite::dba::Decimal tide_height_metres{};
    muscovite::dba::Decimal available_draft{};

    /// Construct from a database row.
    static auto from_row(const pqxx::row& row) -> TideWindow {
        return TideWindow{
            .id = row[0].as<std::string>(),
            .berth_id = row[1].as<std::string>(),
            .tide_height_metres = row[2].as<std::string>(),
            .available_draft = row[3].as<std::string>(),
        };
    }

    /// Try to construct; returns nullopt on missing required field.
    static auto try_from(const pqxx::row& row) -> std::optional<TideWindow> {
        if (row[0].is_null()) return std::nullopt;
        if (row[1].is_null()) return std::nullopt;
        if (row[2].is_null()) return std::nullopt;
        if (row[3].is_null()) return std::nullopt;
        return from_row(row);
    }
};

} // namespace vessel_traffic
