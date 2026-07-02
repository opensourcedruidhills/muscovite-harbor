// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "user_repository_mutations.hpp"
#include <pqxx/pqxx>
#include <stdexcept>

namespace security {

auto UserRepositoryImpl::insert(pqxx::work& tx, const User& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.username,
        entity.email,
        entity.password_hash,
        entity.is_active);
}

auto UserRepositoryImpl::update(pqxx::work& tx, const User& entity) -> void {
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.username);
    params.append(entity.email);
    params.append(entity.password_hash);
    params.append(entity.is_active);
    tx.exec_params(kUpdate, params);
}

auto UserRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace security
