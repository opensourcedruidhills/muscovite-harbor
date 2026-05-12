// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace intermodal_transfer {

auto RailWagonRepositoryImpl::insert(pqxx::work& tx, const RailWagon& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.id,
        entity.wagon_number,
        entity.max_weight_kg,
        entity.slot_id,
    );
}

auto RailWagonRepositoryImpl::update(pqxx::work& tx, const RailWagon& entity) -> void {
    // field params reuse same order as kUpdate (SET ... WHERE id = $N+1)
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.id);
    params.append(entity.wagon_number);
    params.append(entity.max_weight_kg);
    params.append(entity.slot_id);
    tx.exec_params(kUpdate, params);
}

auto RailWagonRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace intermodal_transfer
