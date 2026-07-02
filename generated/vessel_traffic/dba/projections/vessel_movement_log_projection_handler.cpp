// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "vessel_movement_log_projection_handler.hpp"
#include <pqxx/pqxx>

namespace vessel_traffic {

auto VesselMovementLogProjectionHandler::on_vessel_announced(const VesselAnnounced& event) -> void {
    (void)event; // Event payload available for filtering
    pqxx::nontransaction txn{conn_};
    txn.exec("REFRESH MATERIALIZED VIEW CONCURRENTLY vessel_traffic.vessel_movement_log");
}

auto VesselMovementLogProjectionHandler::on_berth_allocated(const BerthAllocated& event) -> void {
    (void)event; // Event payload available for filtering
    pqxx::nontransaction txn{conn_};
    txn.exec("REFRESH MATERIALIZED VIEW CONCURRENTLY vessel_traffic.vessel_movement_log");
}

auto VesselMovementLogProjectionHandler::on_vessel_moored_event(const VesselMooredEvent& event) -> void {
    (void)event; // Event payload available for filtering
    pqxx::nontransaction txn{conn_};
    txn.exec("REFRESH MATERIALIZED VIEW CONCURRENTLY vessel_traffic.vessel_movement_log");
}

auto VesselMovementLogProjectionHandler::on_vessel_departed_event(const VesselDepartedEvent& event) -> void {
    (void)event; // Event payload available for filtering
    pqxx::nontransaction txn{conn_};
    txn.exec("REFRESH MATERIALIZED VIEW CONCURRENTLY vessel_traffic.vessel_movement_log");
}

} // namespace vessel_traffic
