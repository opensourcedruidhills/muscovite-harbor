// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "load_plan_repository_mutations.hpp"
#include <pqxx/pqxx>
#include <stdexcept>

namespace cargo_operations {

auto LoadPlanRepositoryImpl::insert(pqxx::work& tx, const LoadPlan& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.voyage_id,
        entity.created_at,
        entity.status);
}

auto LoadPlanRepositoryImpl::update(pqxx::work& tx, const LoadPlan& entity) -> void {
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.voyage_id);
    params.append(entity.created_at);
    params.append(entity.status);
    tx.exec_params(kUpdate, params);
}

auto LoadPlanRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace cargo_operations
