// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "crane_repository_mutations.hpp"
#include <pqxx/pqxx>
#include <stdexcept>

namespace cargo_operations {

auto CraneRepositoryImpl::insert(pqxx::work& tx, const Crane& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.name,
        entity.crane_type,
        entity.max_lift_kg,
        entity.is_active);
}

auto CraneRepositoryImpl::update(pqxx::work& tx, const Crane& entity) -> void {
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.name);
    params.append(entity.crane_type);
    params.append(entity.max_lift_kg);
    params.append(entity.is_active);
    tx.exec_params(kUpdate, params);
}

auto CraneRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace cargo_operations
