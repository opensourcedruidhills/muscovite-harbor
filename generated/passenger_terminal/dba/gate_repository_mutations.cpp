// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace passenger_terminal {

auto GateRepositoryImpl::insert(pqxx::work& tx, const Gate& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.id,
        entity.code,
        entity.name,
        entity.capacity,
        entity.status,
        entity.voyage_id,
    );
}

auto GateRepositoryImpl::update(pqxx::work& tx, const Gate& entity) -> void {
    // field params reuse same order as kUpdate (SET ... WHERE id = $N+1)
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.id);
    params.append(entity.code);
    params.append(entity.name);
    params.append(entity.capacity);
    params.append(entity.status);
    params.append(entity.voyage_id);
    tx.exec_params(kUpdate, params);
}

auto GateRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace passenger_terminal
