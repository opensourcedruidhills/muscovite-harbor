// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann

#pragma once

#include <string>
#include <functional>

namespace coordination::vessel_arrival_sequence {

/// Orchestrator for VesselArrivalSequence (FTR-870)
class VesselArrivalSequenceOrchestrator {
public:
    /// Step: OrderPilot (context: VesselTraffic)
    void execute_order_pilot(const std::string& correlation_id);

    /// Step: AssignTugs (context: VesselTraffic)
    void execute_assign_tugs(const std::string& correlation_id);

    /// Step: AllocateBerth (context: VesselTraffic)
    void execute_allocate_berth(const std::string& correlation_id);

    /// Step: ActivateCargoPlan (context: CargoOperations)
    void execute_activate_cargo_plan(const std::string& correlation_id);

    /// Step: OpenGates (context: PassengerTerminal)
    void execute_open_gates(const std::string& correlation_id);

    /// Execute full coordination
    void run(const std::string& correlation_id);
};

} // namespace coordination::vessel_arrival_sequence
