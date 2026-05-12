#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace passenger_terminal {

/// Unified DBA struct for Gate.
struct Gate {
    boost::uuids::uuid id{};
    boost::uuids::uuid id{};
    GateCode code{};
    std::string name{};
    std::int32_t capacity{};
    std::string status{};
    boost::uuids::uuid voyage_id{};

    /// Construct from a database row (stub — implementation in .cpp).
    // static auto from_row(const pqxx::row& row) -> Gate;

    /// Try to construct; returns nullopt on missing required field.
    // static auto try_from(const pqxx::row& row) -> std::optional<Gate>;
};

} // namespace passenger_terminal
