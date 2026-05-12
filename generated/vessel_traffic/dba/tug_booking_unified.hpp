#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace vessel_traffic {

/// Unified DBA struct for TugBooking.
struct TugBooking {
    boost::uuids::uuid id{};
    boost::uuids::uuid id{};
    boost::uuids::uuid voyage_id{};
    std::string tug_name{};
    muscovite::dba::Decimal bollard_pull_t{};
    bool is_confirmed{};

    /// Construct from a database row (stub — implementation in .cpp).
    // static auto from_row(const pqxx::row& row) -> TugBooking;

    /// Try to construct; returns nullopt on missing required field.
    // static auto try_from(const pqxx::row& row) -> std::optional<TugBooking>;
};

} // namespace vessel_traffic
