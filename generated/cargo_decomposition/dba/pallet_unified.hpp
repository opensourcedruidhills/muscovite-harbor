#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace cargo_decomposition {

/// Unified DBA struct for Pallet.
struct Pallet {
    boost::uuids::uuid id{};
    PalletId pallet_id{};
    boost::uuids::uuid container_id{};
    muscovite::dba::Decimal weight_kg{};
    muscovite::dba::Decimal length_cm{};
    muscovite::dba::Decimal width_cm{};
    muscovite::dba::Decimal height_cm{};
    HSCode hs_code{};

    /// Construct from a database row.
    static auto from_row(const pqxx::row& row) -> Pallet {
        return Pallet{
            .id = row[0].as<std::string>(),
            .pallet_id = row[1].as<std::string>(),
            .container_id = row[2].as<std::string>(),
            .weight_kg = row[3].as<std::string>(),
            .length_cm = row[4].as<std::string>(),
            .width_cm = row[5].as<std::string>(),
            .height_cm = row[6].as<std::string>(),
            .hs_code = row[7].as<std::string>(),
        };
    }

    /// Try to construct; returns nullopt on missing required field.
    static auto try_from(const pqxx::row& row) -> std::optional<Pallet> {
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

} // namespace cargo_decomposition
