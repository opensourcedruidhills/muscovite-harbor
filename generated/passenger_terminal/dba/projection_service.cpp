// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "projection_service.hpp"
#include <pqxx/pqxx>

namespace passenger_terminal {

ProjectionService::ProjectionService(pqxx::connection& conn, int refresh_interval_seconds)
    : conn_{conn}, refresh_interval_seconds_{refresh_interval_seconds} {}

auto ProjectionService::refresh_all() -> void {
    refresh_departure_board();
}

auto ProjectionService::refresh_departure_board() -> void {
    pqxx::nontransaction tx{conn_};
    tx.exec0("REFRESH MATERIALIZED VIEW CONCURRENTLY passenger_terminal.departure_board");
}

auto ProjectionService::is_stale_departure_board() const -> bool {
    // WHY: #1483 — check pg_stat_user_tables for last vacuum/analyze as proxy
    auto tx = conn_.begin();
    auto result = tx.exec_params(
        "SELECT EXTRACT(EPOCH FROM (NOW() - COALESCE(last_analyze, last_autoanalyze, '1970-01-01'))) > $1 "
        "FROM pg_stat_user_tables WHERE relname = $2",
        refresh_interval_seconds_, "departure_board");
    tx.commit();
    if (result.empty()) { return true; }
    return result[0][0].as<bool>();
}

} // namespace passenger_terminal
