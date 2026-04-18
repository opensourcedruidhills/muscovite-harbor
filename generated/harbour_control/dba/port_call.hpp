#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <boost/uuid/uuid.hpp>
#include <cstdint>
#include <muscovite/dba/decimal.hpp>
#include <muscovite/dba/timestamp.hpp>
#include <string>

namespace harbour_control {

/// Read-only aggregation across VesselTraffic, CargoOps, and billing
struct PortCall {
    using Id = boost::uuids::uuid;

    Id id{};
    std::string vessel_name{};
    std::string imo_number{};
    std::string berth_code{};
    muscovite::dba::Timestamp arrival_time{};
    muscovite::dba::Timestamp departure_time{};
    std::int32_t container_count{};
    std::int32_t hazmat_permits{};
    muscovite::dba::Decimal total_billed{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_vessel_name() const noexcept -> const std::string& { return vessel_name; }
    [[nodiscard]] auto get_imo_number() const noexcept -> const std::string& { return imo_number; }
    [[nodiscard]] auto get_berth_code() const noexcept -> const std::string& { return berth_code; }
    [[nodiscard]] auto get_arrival_time() const noexcept -> const muscovite::dba::Timestamp& { return arrival_time; }
    [[nodiscard]] auto get_departure_time() const noexcept -> const muscovite::dba::Timestamp& { return departure_time; }
    [[nodiscard]] auto get_container_count() const noexcept -> std::int32_t { return container_count; }
    [[nodiscard]] auto get_hazmat_permits() const noexcept -> std::int32_t { return hazmat_permits; }
    [[nodiscard]] auto get_total_billed() const noexcept -> const muscovite::dba::Decimal& { return total_billed; }
};

} // namespace harbour_control
