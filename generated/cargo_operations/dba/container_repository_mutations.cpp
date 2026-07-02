// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "container_repository_mutations.hpp"
#include <pqxx/pqxx>
#include <stdexcept>

namespace cargo_operations {

auto ContainerRepositoryImpl::insert(pqxx::work& tx, const Container& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.container_number,
        entity.size_category,
        entity.hazmat_class,
        entity.voyage_id,
        entity.yard_slot_id,
        entity.status);
}

auto ContainerRepositoryImpl::update(pqxx::work& tx, const Container& entity) -> void {
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.container_number);
    params.append(entity.size_category);
    params.append(entity.hazmat_class);
    params.append(entity.voyage_id);
    params.append(entity.yard_slot_id);
    params.append(entity.status);
    tx.exec_params(kUpdate, params);
}

auto ContainerRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace cargo_operations
