#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace intermodal_transfer {

/// Unified DBA struct for BargeBooking.
struct BargeBooking {
    boost::uuids::uuid id{};
    boost::uuids::uuid id{};
    std::string barge_name{};
    std::int32_t capacity_teu{};
    muscovite::dba::Timestamp departure_at{};
    std::string status{};

    /// Construct from a database row (stub — implementation in .cpp).
    // static auto from_row(const pqxx::row& row) -> BargeBooking;

    /// Try to construct; returns nullopt on missing required field.
    // static auto try_from(const pqxx::row& row) -> std::optional<BargeBooking>;
};

} // namespace intermodal_transfer
