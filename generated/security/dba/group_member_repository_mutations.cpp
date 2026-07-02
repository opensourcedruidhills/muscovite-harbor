// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "group_member_repository_mutations.hpp"
#include <pqxx/pqxx>
#include <stdexcept>

namespace security {

auto GroupMemberRepositoryImpl::insert(pqxx::work& tx, const GroupMember& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.group_id,
        entity.user_id);
}

auto GroupMemberRepositoryImpl::update(pqxx::work& tx, const GroupMember& entity) -> void {
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.group_id);
    params.append(entity.user_id);
    tx.exec_params(kUpdate, params);
}

auto GroupMemberRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace security
