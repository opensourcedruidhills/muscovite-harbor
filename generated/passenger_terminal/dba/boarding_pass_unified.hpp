#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace passenger_terminal {

/// Unified DBA struct for BoardingPass.
struct BoardingPass {
    boost::uuids::uuid id{};
    boost::uuids::uuid id{};
    boost::uuids::uuid passenger_id{};
    boost::uuids::uuid gate_id{};
    std::string boarding_group{};
    std::string seat_number{};
    muscovite::dba::Timestamp issued_at{};
    muscovite::dba::Timestamp scanned_at{};

    /// Construct from a database row (stub — implementation in .cpp).
    // static auto from_row(const pqxx::row& row) -> BoardingPass;

    /// Try to construct; returns nullopt on missing required field.
    // static auto try_from(const pqxx::row& row) -> std::optional<BoardingPass>;
};

} // namespace passenger_terminal
