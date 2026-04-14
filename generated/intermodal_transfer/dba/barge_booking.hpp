#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <boost/uuid/uuid.hpp>
#include <cstdint>
#include <string>
#include <string>

namespace intermodal_transfer {

/// Booking for barge transport of containers
struct BargeBooking {
    using Id = boost::uuids::uuid;

    Id id{};
    boost::uuids::uuid id{};
    std::string barge_name{};
    std::int32_t capacity_teu{};
    muscovite::dba::Timestamp departure_at{};
    std::string status{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_id() const noexcept -> const boost::uuids::uuid& { return id; }
    [[nodiscard]] auto get_barge_name() const noexcept -> const std::string& { return barge_name; }
    [[nodiscard]] auto get_capacity_teu() const noexcept -> std::int32_t { return capacity_teu; }
    [[nodiscard]] auto get_departure_at() const noexcept -> const muscovite::dba::Timestamp& { return departure_at; }
    [[nodiscard]] auto get_status() const noexcept -> const std::string& { return status; }
};

} // namespace intermodal_transfer
