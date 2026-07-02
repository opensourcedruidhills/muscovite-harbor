// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "access_control_entry_repository_mutations.hpp"
#include <pqxx/pqxx>
#include <stdexcept>

namespace security {

auto AccessControlEntryRepositoryImpl::insert(pqxx::work& tx, const AccessControlEntry& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.principal,
        entity.resource,
        entity.permission,
        entity.effect);
}

auto AccessControlEntryRepositoryImpl::update(pqxx::work& tx, const AccessControlEntry& entity) -> void {
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.principal);
    params.append(entity.resource);
    params.append(entity.permission);
    params.append(entity.effect);
    tx.exec_params(kUpdate, params);
}

auto AccessControlEntryRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace security
