#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <boost/uuid/uuid.hpp>
#include <muscovite/dba/timestamp.hpp>
#include <string>
#include "types/truck_plate.hpp"

namespace intermodal_transfer {

/// A truck arriving for container pickup
struct TruckVisit {
    using Id = boost::uuids::uuid;

    Id id{};
    TruckPlate truck_plate{};
    std::string carrier_name{};
    boost::uuids::uuid slot_id{};
    muscovite::dba::Timestamp arrived_at{};
    muscovite::dba::Timestamp departed_at{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_truck_plate() const noexcept -> const TruckPlate& { return truck_plate; }
    [[nodiscard]] auto get_carrier_name() const noexcept -> const std::string& { return carrier_name; }
    [[nodiscard]] auto get_slot_id() const noexcept -> const boost::uuids::uuid& { return slot_id; }
    [[nodiscard]] auto get_arrived_at() const noexcept -> const muscovite::dba::Timestamp& { return arrived_at; }
    [[nodiscard]] auto get_departed_at() const noexcept -> const muscovite::dba::Timestamp& { return departed_at; }
};

} // namespace intermodal_transfer
