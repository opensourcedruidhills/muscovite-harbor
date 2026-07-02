#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>

namespace passenger_terminal {

/// Departure display board — updated on gate status change
/// Event-driven projection handler for DepartureBoard (ON_EVENT refresh).
class DepartureBoardProjectionHandler {
public:
    DepartureBoardProjectionHandler(pqxx::connection& conn) : conn_{conn} {}

    // Per-trigger-event handler methods
    auto on_gate_status_changed(const GateStatusChanged& event) -> void;

    private:
        pqxx::connection& conn_;
};

} // namespace passenger_terminal
