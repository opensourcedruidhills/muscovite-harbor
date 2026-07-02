// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "role_repository_mutations.hpp"
#include <pqxx/pqxx>
#include <stdexcept>

namespace security {

auto RoleRepositoryImpl::insert(pqxx::work& tx, const Role& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.name,
        entity.description,
        entity.permissions);
}

auto RoleRepositoryImpl::update(pqxx::work& tx, const Role& entity) -> void {
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.name);
    params.append(entity.description);
    params.append(entity.permissions);
    tx.exec_params(kUpdate, params);
}

auto RoleRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace security
