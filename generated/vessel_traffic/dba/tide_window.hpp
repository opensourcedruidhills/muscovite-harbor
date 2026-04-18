#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <boost/uuid/uuid.hpp>
#include <muscovite/dba/decimal.hpp>

namespace vessel_traffic {

/// A tidal window with navigable draft at a specific berth
struct TideWindow {
    using Id = boost::uuids::uuid;

    Id id{};
    boost::uuids::uuid berth_id{};
    muscovite::dba::Decimal tide_height_metres{};
    muscovite::dba::Decimal available_draft{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_berth_id() const noexcept -> const boost::uuids::uuid& { return berth_id; }
    [[nodiscard]] auto get_tide_height_metres() const noexcept -> const muscovite::dba::Decimal& { return tide_height_metres; }
    [[nodiscard]] auto get_available_draft() const noexcept -> const muscovite::dba::Decimal& { return available_draft; }
};

} // namespace vessel_traffic
