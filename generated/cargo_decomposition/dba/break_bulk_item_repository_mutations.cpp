// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace cargo_decomposition {

auto BreakBulkItemRepositoryImpl::insert(pqxx::work& tx, const BreakBulkItem& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.id,
        entity.container_id,
        entity.item_type,
        entity.weight_kg,
        entity.requires_crane,
    );
}

auto BreakBulkItemRepositoryImpl::update(pqxx::work& tx, const BreakBulkItem& entity) -> void {
    // field params reuse same order as kUpdate (SET ... WHERE id = $N+1)
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.id);
    params.append(entity.container_id);
    params.append(entity.item_type);
    params.append(entity.weight_kg);
    params.append(entity.requires_crane);
    tx.exec_params(kUpdate, params);
}

auto BreakBulkItemRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace cargo_decomposition
