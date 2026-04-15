#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <boost/uuid/uuid.hpp>
#include <muscovite/dba/decimal.hpp>
#include <string>
#include <string>

namespace cargo_decomposition {

/// An individual parcel within a pallet
struct Parcel {
    using Id = boost::uuids::uuid;

    Id id{};
    TrackingNumber tracking_number{};
    boost::uuids::uuid pallet_id{};
    muscovite::dba::Decimal weight_kg{};
    HSCode hs_code{};
    std::string description{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_tracking_number() const noexcept -> const TrackingNumber& { return tracking_number; }
    [[nodiscard]] auto get_pallet_id() const noexcept -> const boost::uuids::uuid& { return pallet_id; }
    [[nodiscard]] auto get_weight_kg() const noexcept -> const muscovite::dba::Decimal& { return weight_kg; }
    [[nodiscard]] auto get_hs_code() const noexcept -> const HSCode& { return hs_code; }
    [[nodiscard]] auto get_description() const noexcept -> const std::string& { return description; }
};

} // namespace cargo_decomposition
