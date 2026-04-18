#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <boost/uuid/uuid.hpp>
#include <muscovite/dba/decimal.hpp>
#include <string>

namespace vessel_traffic {

/// Booking of a tug for vessel manoeuvring
struct TugBooking {
    using Id = boost::uuids::uuid;

    Id id{};
    boost::uuids::uuid voyage_id{};
    std::string tug_name{};
    muscovite::dba::Decimal bollard_pull_t{};
    bool is_confirmed{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_voyage_id() const noexcept -> const boost::uuids::uuid& { return voyage_id; }
    [[nodiscard]] auto get_tug_name() const noexcept -> const std::string& { return tug_name; }
    [[nodiscard]] auto get_bollard_pull_t() const noexcept -> const muscovite::dba::Decimal& { return bollard_pull_t; }
    [[nodiscard]] auto get_is_confirmed() const noexcept -> bool { return is_confirmed; }
};

} // namespace vessel_traffic
