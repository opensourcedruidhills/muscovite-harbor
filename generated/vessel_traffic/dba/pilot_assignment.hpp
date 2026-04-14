#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <boost/uuid/uuid.hpp>
#include <string>
#include <string>

namespace vessel_traffic {

/// Assignment of a pilot to a voyage
struct PilotAssignment {
    using Id = boost::uuids::uuid;

    Id id{};
    boost::uuids::uuid id{};
    boost::uuids::uuid voyage_id{};
    std::string pilot_name{};
    std::string pilot_zone{};
    muscovite::dba::Timestamp boarding_time{};
    muscovite::dba::Timestamp disembark_time{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_id() const noexcept -> const boost::uuids::uuid& { return id; }
    [[nodiscard]] auto get_voyage_id() const noexcept -> const boost::uuids::uuid& { return voyage_id; }
    [[nodiscard]] auto get_pilot_name() const noexcept -> const std::string& { return pilot_name; }
    [[nodiscard]] auto get_pilot_zone() const noexcept -> const std::string& { return pilot_zone; }
    [[nodiscard]] auto get_boarding_time() const noexcept -> const muscovite::dba::Timestamp& { return boarding_time; }
    [[nodiscard]] auto get_disembark_time() const noexcept -> const muscovite::dba::Timestamp& { return disembark_time; }
};

} // namespace vessel_traffic
