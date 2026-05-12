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
    boost::uuids::uuid id{};
    PalletId pallet_id{};
    boost::uuids::uuid container_id{};
    muscovite::dba::Decimal weight_kg{};
    muscovite::dba::Decimal length_cm{};
    muscovite::dba::Decimal width_cm{};
    muscovite::dba::Decimal height_cm{};
    HSCode hs_code{};

    /// Construct from a database row (stub — implementation in .cpp).
    // static auto from_row(const pqxx::row& row) -> Pallet;

    /// Try to construct; returns nullopt on missing required field.
    // static auto try_from(const pqxx::row& row) -> std::optional<Pallet>;
};

} // namespace cargo_decomposition
