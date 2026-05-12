#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace vessel_traffic {

/// Unified DBA struct for Berth.
struct Berth {
    boost::uuids::uuid id{};
    boost::uuids::uuid id{};
    BerthCode code{};
    std::string name{};
    muscovite::dba::Decimal max_loa_metres{};
    muscovite::dba::Decimal max_draft_metres{};
    muscovite::dba::Decimal max_beam_metres{};
    bool has_crane_access{};
    bool has_reefer_plugs{};
    bool is_active{};

    /// Construct from a database row (stub — implementation in .cpp).
    // static auto from_row(const pqxx::row& row) -> Berth;

    /// Try to construct; returns nullopt on missing required field.
    // static auto try_from(const pqxx::row& row) -> std::optional<Berth>;
};

} // namespace vessel_traffic
