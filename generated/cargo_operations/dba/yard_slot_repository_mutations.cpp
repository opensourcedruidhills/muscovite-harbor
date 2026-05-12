// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace cargo_operations {

auto YardSlotRepositoryImpl::insert(pqxx::work& tx, const YardSlot& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.id,
        entity.code,
        entity.max_weight_kg,
        entity.max_tier,
        entity.has_power,
        entity.is_occupied,
    );
}

auto YardSlotRepositoryImpl::update(pqxx::work& tx, const YardSlot& entity) -> void {
    // field params reuse same order as kUpdate (SET ... WHERE id = $N+1)
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.id);
    params.append(entity.code);
    params.append(entity.max_weight_kg);
    params.append(entity.max_tier);
    params.append(entity.has_power);
    params.append(entity.is_occupied);
    tx.exec_params(kUpdate, params);
}

auto YardSlotRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace cargo_operations
