#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace vessel_traffic {

/// Unified DBA struct for PilotAssignment.
struct PilotAssignment {
    boost::uuids::uuid id{};
    boost::uuids::uuid id{};
    boost::uuids::uuid voyage_id{};
    std::string pilot_name{};
    std::string pilot_zone{};
    muscovite::dba::Timestamp boarding_time{};
    muscovite::dba::Timestamp disembark_time{};

    /// Construct from a database row (stub — implementation in .cpp).
    // static auto from_row(const pqxx::row& row) -> PilotAssignment;

    /// Try to construct; returns nullopt on missing required field.
    // static auto try_from(const pqxx::row& row) -> std::optional<PilotAssignment>;
};

} // namespace vessel_traffic
