// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace cargo_operations {

auto LoadPlanRepositoryImpl::insert(pqxx::work& tx, const LoadPlan& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.id,
        entity.voyage_id,
        entity.created_at,
        entity.status,
    );
}

auto LoadPlanRepositoryImpl::update(pqxx::work& tx, const LoadPlan& entity) -> void {
    // field params reuse same order as kUpdate (SET ... WHERE id = $N+1)
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.id);
    params.append(entity.voyage_id);
    params.append(entity.created_at);
    params.append(entity.status);
    tx.exec_params(kUpdate, params);
}

auto LoadPlanRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace cargo_operations
