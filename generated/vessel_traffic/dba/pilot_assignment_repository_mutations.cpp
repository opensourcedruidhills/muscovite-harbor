// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "pilot_assignment_repository_mutations.hpp"
#include <pqxx/pqxx>
#include <stdexcept>

namespace vessel_traffic {

auto PilotAssignmentRepositoryImpl::insert(pqxx::work& tx, const PilotAssignment& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.voyage_id,
        entity.pilot_name,
        entity.pilot_zone,
        entity.boarding_time,
        entity.disembark_time);
}

auto PilotAssignmentRepositoryImpl::update(pqxx::work& tx, const PilotAssignment& entity) -> void {
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.voyage_id);
    params.append(entity.pilot_name);
    params.append(entity.pilot_zone);
    params.append(entity.boarding_time);
    params.append(entity.disembark_time);
    tx.exec_params(kUpdate, params);
}

auto PilotAssignmentRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace vessel_traffic
