#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <boost/uuid/uuid.hpp>
#include <muscovite/dba/timestamp.hpp>
#include <string>
#include <string>

namespace passenger_terminal {

/// Issued boarding pass for a passenger
struct BoardingPass {
    using Id = boost::uuids::uuid;

    Id id{};
    boost::uuids::uuid passenger_id{};
    boost::uuids::uuid gate_id{};
    std::string boarding_group{};
    std::string seat_number{};
    muscovite::dba::Timestamp issued_at{};
    muscovite::dba::Timestamp scanned_at{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_passenger_id() const noexcept -> const boost::uuids::uuid& { return passenger_id; }
    [[nodiscard]] auto get_gate_id() const noexcept -> const boost::uuids::uuid& { return gate_id; }
    [[nodiscard]] auto get_boarding_group() const noexcept -> const std::string& { return boarding_group; }
    [[nodiscard]] auto get_seat_number() const noexcept -> const std::string& { return seat_number; }
    [[nodiscard]] auto get_issued_at() const noexcept -> const muscovite::dba::Timestamp& { return issued_at; }
    [[nodiscard]] auto get_scanned_at() const noexcept -> const muscovite::dba::Timestamp& { return scanned_at; }
};

} // namespace passenger_terminal
