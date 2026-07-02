// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "departure_board_projection_handler.hpp"
#include <pqxx/pqxx>

namespace passenger_terminal {

auto DepartureBoardProjectionHandler::on_gate_status_changed(const GateStatusChanged& event) -> void {
    (void)event; // Event payload available for filtering
    pqxx::nontransaction txn{conn_};
    txn.exec("REFRESH MATERIALIZED VIEW CONCURRENTLY passenger_terminal.departure_board");
}

} // namespace passenger_terminal
