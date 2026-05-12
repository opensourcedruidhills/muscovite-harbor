#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace vessel_traffic {

/// Unified DBA struct for Voyage.
struct Voyage {
    boost::uuids::uuid id{};
    boost::uuids::uuid id{};
    boost::uuids::uuid vessel_id{};
    boost::uuids::uuid berth_id{};
    std::string voyage_number{};
    muscovite::dba::Timestamp eta{};
    muscovite::dba::Timestamp ata{};
    muscovite::dba::Timestamp etd{};
    muscovite::dba::Timestamp atd{};
    std::string cargo_category{};
    std::string status{};

    /// Construct from a database row (stub — implementation in .cpp).
    // static auto from_row(const pqxx::row& row) -> Voyage;

    /// Try to construct; returns nullopt on missing required field.
    // static auto try_from(const pqxx::row& row) -> std::optional<Voyage>;
};

} // namespace vessel_traffic
