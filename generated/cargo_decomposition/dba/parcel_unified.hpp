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
    boost::uuids::uuid id{};
    TrackingNumber tracking_number{};
    boost::uuids::uuid pallet_id{};
    muscovite::dba::Decimal weight_kg{};
    HSCode hs_code{};
    std::string description{};

    /// Construct from a database row (stub — implementation in .cpp).
    // static auto from_row(const pqxx::row& row) -> Parcel;

    /// Try to construct; returns nullopt on missing required field.
    // static auto try_from(const pqxx::row& row) -> std::optional<Parcel>;
};

} // namespace cargo_decomposition
