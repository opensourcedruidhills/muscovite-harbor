// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "arrival_board_projection_handler.hpp"
#include <pqxx/pqxx>

namespace passenger_terminal {

auto ArrivalBoardProjectionHandler::on_passenger_checked_in(const PassengerCheckedIn& event) -> void {
    (void)event; // Event payload available for filtering
    pqxx::nontransaction txn{conn_};
    txn.exec("REFRESH MATERIALIZED VIEW CONCURRENTLY passenger_terminal.arrival_board");
}

auto ArrivalBoardProjectionHandler::on_boarding_pass_issued(const BoardingPassIssued& event) -> void {
    (void)event; // Event payload available for filtering
    pqxx::nontransaction txn{conn_};
    txn.exec("REFRESH MATERIALIZED VIEW CONCURRENTLY passenger_terminal.arrival_board");
}

} // namespace passenger_terminal
