// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "truck_visit_repository_mutations.hpp"
#include <pqxx/pqxx>
#include <stdexcept>

namespace intermodal_transfer {

auto TruckVisitRepositoryImpl::insert(pqxx::work& tx, const TruckVisit& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.truck_plate,
        entity.carrier_name,
        entity.slot_id,
        entity.arrived_at,
        entity.departed_at);
}

auto TruckVisitRepositoryImpl::update(pqxx::work& tx, const TruckVisit& entity) -> void {
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.truck_plate);
    params.append(entity.carrier_name);
    params.append(entity.slot_id);
    params.append(entity.arrived_at);
    params.append(entity.departed_at);
    tx.exec_params(kUpdate, params);
}

auto TruckVisitRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace intermodal_transfer
