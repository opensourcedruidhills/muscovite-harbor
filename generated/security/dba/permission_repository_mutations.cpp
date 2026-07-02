// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "permission_repository_mutations.hpp"
#include <pqxx/pqxx>
#include <stdexcept>

namespace security {

auto PermissionRepositoryImpl::insert(pqxx::work& tx, const Permission& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.name,
        entity.resource,
        entity.action);
}

auto PermissionRepositoryImpl::update(pqxx::work& tx, const Permission& entity) -> void {
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.name);
    params.append(entity.resource);
    params.append(entity.action);
    tx.exec_params(kUpdate, params);
}

auto PermissionRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace security
