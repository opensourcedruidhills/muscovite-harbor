#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>

namespace vessel_traffic {

/// Audit log of all vessel movements (maritime law compliance)
/// Event-driven projection handler for VesselMovementLog (ON_EVENT refresh).
class VesselMovementLogProjectionHandler {
public:
    VesselMovementLogProjectionHandler(pqxx::connection& conn) : conn_{conn} {}

    // Per-trigger-event handler methods
    auto on_vessel_announced(const VesselAnnounced& event) -> void;
    auto on_berth_allocated(const BerthAllocated& event) -> void;
    auto on_vessel_moored_event(const VesselMooredEvent& event) -> void;
    auto on_vessel_departed_event(const VesselDepartedEvent& event) -> void;

    private:
        pqxx::connection& conn_;
};

} // namespace vessel_traffic
