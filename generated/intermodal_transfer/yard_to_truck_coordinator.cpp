// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "yard_to_truck_coordinator.hpp"

namespace muscovite_harbor {
namespace intermodal_transfer {

void YardToTruckCoordinator::start() {
    handle_move_to_gate();
}

void YardToTruckCoordinator::handle_step(std::string_view step_name) {
    if (step_name == "MoveToGate") {
        handle_move_to_gate();
        return;
    }
    if (step_name == "WeighBridge") {
        handle_weigh_bridge();
        return;
    }
    if (step_name == "GateRelease") {
        handle_gate_release();
        return;
    }
}

void YardToTruckCoordinator::handle_move_to_gate() {
    // command MoveContainer
    handle_weigh_bridge();
}

void YardToTruckCoordinator::handle_weigh_bridge() {
    // event ContainerAtGate
    handle_gate_release();
}

void YardToTruckCoordinator::handle_gate_release() {
    // event ContainerWeighed
    on_complete();
}

void YardToTruckCoordinator::on_complete() {
}

} // namespace intermodal_transfer
} // namespace muscovite_harbor
