#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <boost/uuid/uuid.hpp>
#include <string>
#include <string>

namespace passenger_terminal {

/// A passenger travelling on a voyage
struct Passenger {
    using Id = boost::uuids::uuid;

    Id id{};
    BookingReference booking_ref{};
    std::string passenger_type{};
    boost::uuids::uuid voyage_id{};
    std::string status{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_booking_ref() const noexcept -> const BookingReference& { return booking_ref; }
    [[nodiscard]] auto get_passenger_type() const noexcept -> const std::string& { return passenger_type; }
    [[nodiscard]] auto get_voyage_id() const noexcept -> const boost::uuids::uuid& { return voyage_id; }
    [[nodiscard]] auto get_status() const noexcept -> const std::string& { return status; }
};

} // namespace passenger_terminal
