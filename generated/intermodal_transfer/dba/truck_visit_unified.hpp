#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace intermodal_transfer {

/// Unified DBA struct for TruckVisit.
struct TruckVisit {
    boost::uuids::uuid id{};
    boost::uuids::uuid id{};
    TruckPlate truck_plate{};
    std::string carrier_name{};
    boost::uuids::uuid slot_id{};
    muscovite::dba::Timestamp arrived_at{};
    muscovite::dba::Timestamp departed_at{};

    /// Construct from a database row (stub — implementation in .cpp).
    // static auto from_row(const pqxx::row& row) -> TruckVisit;

    /// Try to construct; returns nullopt on missing required field.
    // static auto try_from(const pqxx::row& row) -> std::optional<TruckVisit>;
};

} // namespace intermodal_transfer
