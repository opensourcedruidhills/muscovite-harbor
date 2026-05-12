#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace vessel_traffic {

/// Unified DBA struct for Vessel.
struct Vessel {
    boost::uuids::uuid id{};
    boost::uuids::uuid id{};
    IMONumber imo_number{};
    MMSI mmsi{};
    CallSign call_sign{};
    std::string name{};
    std::string vessel_type{};
    std::string flag_state{};
    bool is_active{};

    /// Construct from a database row (stub — implementation in .cpp).
    // static auto from_row(const pqxx::row& row) -> Vessel;

    /// Try to construct; returns nullopt on missing required field.
    // static auto try_from(const pqxx::row& row) -> std::optional<Vessel>;
};

} // namespace vessel_traffic
