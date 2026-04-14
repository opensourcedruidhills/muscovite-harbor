// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "projection_service.hpp"

namespace passenger_terminal {

auto ProjectionService::refresh_all() -> void {
    refresh_departure_board();
}

auto ProjectionService::refresh_departure_board() -> void {
    // REFRESH MATERIALIZED VIEW passenger_terminal.departure_board;
}

auto ProjectionService::is_stale_departure_board() const -> bool {
    return false; // TODO: check last refresh timestamp
}

} // namespace passenger_terminal
