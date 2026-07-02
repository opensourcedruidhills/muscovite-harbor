// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "context_privilege_repository_mutations.hpp"
#include <pqxx/pqxx>
#include <stdexcept>

namespace security {

auto ContextPrivilegeRepositoryImpl::insert(pqxx::work& tx, const ContextPrivilege& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.context_name,
        entity.group_id,
        entity.privilege);
}

auto ContextPrivilegeRepositoryImpl::update(pqxx::work& tx, const ContextPrivilege& entity) -> void {
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.context_name);
    params.append(entity.group_id);
    params.append(entity.privilege);
    tx.exec_params(kUpdate, params);
}

auto ContextPrivilegeRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace security
