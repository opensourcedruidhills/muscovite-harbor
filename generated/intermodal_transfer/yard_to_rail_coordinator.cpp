// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "yard_to_rail_coordinator.hpp"

namespace muscovite_harbor {
namespace intermodal_transfer {

void YardToRailCoordinator::start() {
    handle_move_to_rail_head();
}

void YardToRailCoordinator::handle_step(std::string_view step_name) {
    if (step_name == "MoveToRailHead") {
        handle_move_to_rail_head();
        return;
    }
    if (step_name == "CraneToWagon") {
        handle_crane_to_wagon();
        return;
    }
    if (step_name == "TrainDepart") {
        handle_train_depart();
        return;
    }
}

void YardToRailCoordinator::handle_move_to_rail_head() {
    // command MoveToRailHead
    handle_crane_to_wagon();
}

void YardToRailCoordinator::handle_crane_to_wagon() {
    // event ContainerAtRailHead
    handle_train_depart();
}

void YardToRailCoordinator::handle_train_depart() {
    // event ContainerOnWagon
    on_complete();
}

void YardToRailCoordinator::on_complete() {
}

} // namespace intermodal_transfer
} // namespace muscovite_harbor
