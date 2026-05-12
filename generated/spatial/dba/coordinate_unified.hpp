#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace spatial {

/// Unified DBA struct for Coordinate.
struct Coordinate {
    boost::uuids::uuid id{};
    muscovite::dba::Decimal latitude{};
    muscovite::dba::Decimal longitude{};
    muscovite::dba::Decimal altitude{};
    std::int32_t srid{};

    /// Construct from a database row (stub — implementation in .cpp).
    // static auto from_row(const pqxx::row& row) -> Coordinate;

    /// Try to construct; returns nullopt on missing required field.
    // static auto try_from(const pqxx::row& row) -> std::optional<Coordinate>;
};

} // namespace spatial
