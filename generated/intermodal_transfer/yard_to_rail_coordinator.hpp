// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#pragma once

#include <string_view>

namespace muscovite_harbor {
namespace intermodal_transfer {

class YardToRailCoordinator {
public:
    void start();
    void handle_step(std::string_view step_name);
    void handle_move_to_rail_head();
    void handle_crane_to_wagon();
    void handle_train_depart();
    void on_complete();
};

} // namespace intermodal_transfer
} // namespace muscovite_harbor
