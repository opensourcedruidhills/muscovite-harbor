// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "user_role_repository_mutations.hpp"
#include <pqxx/pqxx>
#include <stdexcept>

namespace security {

auto UserRoleRepositoryImpl::insert(pqxx::work& tx, const UserRole& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.user_id,
        entity.role_id);
}

auto UserRoleRepositoryImpl::update(pqxx::work& tx, const UserRole& entity) -> void {
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.user_id);
    params.append(entity.role_id);
    tx.exec_params(kUpdate, params);
}

auto UserRoleRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace security
