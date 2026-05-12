// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace security {

auto RoleRepositoryImpl::insert(pqxx::work& tx, const Role& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.name,
        entity.description,
        entity.permissions,
    );
}

auto RoleRepositoryImpl::update(pqxx::work& tx, const Role& entity) -> void {
    // field params reuse same order as kUpdate (SET ... WHERE id = $N+1)
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
