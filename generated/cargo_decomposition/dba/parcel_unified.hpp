#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace cargo_decomposition {

/// Unified DBA struct for Parcel.
struct Parcel {
    boost::uuids::uuid id{};
    TrackingNumber tracking_number{};
    boost::uuids::uuid pallet_id{};
    muscovite::dba::Decimal weight_kg{};
    HSCode hs_code{};
    std::string description{};

    /// Construct from a database row.
    static auto from_row(const pqxx::row& row) -> Parcel {
        return Parcel{
            .id = row[0].as<std::string>(),
            .tracking_number = row[1].as<std::string>(),
            .pallet_id = row[2].as<std::string>(),
            .weight_kg = row[3].as<std::string>(),
            .hs_code = row[4].as<std::string>(),
            .description = row[5].as<std::string>(),
        };
    }

    /// Try to construct; returns nullopt on missing required field.
    static auto try_from(const pqxx::row& row) -> std::optional<Parcel> {
        if (row[0].is_null()) return std::nullopt;
        if (row[1].is_null()) return std::nullopt;
        if (row[2].is_null()) return std::nullopt;
        if (row[3].is_null()) return std::nullopt;
        if (row[4].is_null()) return std::nullopt;
        if (row[5].is_null()) return std::nullopt;
        return from_row(row);
    }
};

} // namespace cargo_decomposition
