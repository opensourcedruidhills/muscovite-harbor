// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace spatial {

auto RegionRepositoryImpl::insert(pqxx::work& tx, const Region& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.name,
        entity.boundary,
        entity.center,
    );
}

auto RegionRepositoryImpl::update(pqxx::work& tx, const Region& entity) -> void {
    // field params reuse same order as kUpdate (SET ... WHERE id = $N+1)
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.name);
    params.append(entity.boundary);
    params.append(entity.center);
    tx.exec_params(kUpdate, params);
}

auto RegionRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace spatial
