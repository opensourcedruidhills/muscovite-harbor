// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "discharge_sequence_repository_mutations.hpp"
#include <pqxx/pqxx>
#include <stdexcept>

namespace cargo_operations {

auto DischargeSequenceRepositoryImpl::insert(pqxx::work& tx, const DischargeSequence& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.load_plan_id,
        entity.container_id,
        entity.sequence_order,
        entity.crane_id);
}

auto DischargeSequenceRepositoryImpl::update(pqxx::work& tx, const DischargeSequence& entity) -> void {
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.load_plan_id);
    params.append(entity.container_id);
    params.append(entity.sequence_order);
    params.append(entity.crane_id);
    tx.exec_params(kUpdate, params);
}

auto DischargeSequenceRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace cargo_operations
