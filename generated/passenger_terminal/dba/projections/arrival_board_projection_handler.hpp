#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>

namespace passenger_terminal {

/// Real-time arrival board — updated on check-in and boarding events
/// Event-driven projection handler for ArrivalBoard (ON_EVENT refresh).
class ArrivalBoardProjectionHandler {
public:
    ArrivalBoardProjectionHandler(pqxx::connection& conn) : conn_{conn} {}

    // Per-trigger-event handler methods
    auto on_passenger_checked_in(const PassengerCheckedIn& event) -> void;
    auto on_boarding_pass_issued(const BoardingPassIssued& event) -> void;

    private:
        pqxx::connection& conn_;
};

} // namespace passenger_terminal
