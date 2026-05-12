#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace harbour_control {

/// Unified DBA struct for PortCall.
struct PortCall {
    boost::uuids::uuid id{};
    boost::uuids::uuid id{};
    std::string vessel_name{};
    std::string imo_number{};
    std::string berth_code{};
    muscovite::dba::Timestamp arrival_time{};
    muscovite::dba::Timestamp departure_time{};
    std::int32_t container_count{};
    std::int32_t hazmat_permits{};
    muscovite::dba::Decimal total_billed{};

    /// Construct from a database row (stub — implementation in .cpp).
    // static auto from_row(const pqxx::row& row) -> PortCall;

    /// Try to construct; returns nullopt on missing required field.
    // static auto try_from(const pqxx::row& row) -> std::optional<PortCall>;
};

} // namespace harbour_control
