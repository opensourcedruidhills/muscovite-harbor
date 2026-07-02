// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "reefer_unit_repository_mutations.hpp"
#include <pqxx/pqxx>
#include <stdexcept>

namespace cargo_operations {

auto ReeferUnitRepositoryImpl::insert(pqxx::work& tx, const ReeferUnit& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.container_id,
        entity.target_temp_c,
        entity.current_temp_c,
        entity.is_powered);
}

auto ReeferUnitRepositoryImpl::update(pqxx::work& tx, const ReeferUnit& entity) -> void {
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.container_id);
    params.append(entity.target_temp_c);
    params.append(entity.current_temp_c);
    params.append(entity.is_powered);
    tx.exec_params(kUpdate, params);
}

auto ReeferUnitRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace cargo_operations
