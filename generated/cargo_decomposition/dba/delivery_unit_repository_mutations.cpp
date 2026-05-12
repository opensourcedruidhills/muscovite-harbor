// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace cargo_decomposition {

auto DeliveryUnitRepositoryImpl::insert(pqxx::work& tx, const DeliveryUnit& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.id,
        entity.tracking_number,
        entity.destination,
        entity.carrier,
        entity.dispatched_at,
    );
}

auto DeliveryUnitRepositoryImpl::update(pqxx::work& tx, const DeliveryUnit& entity) -> void {
    // field params reuse same order as kUpdate (SET ... WHERE id = $N+1)
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.id);
    params.append(entity.tracking_number);
    params.append(entity.destination);
    params.append(entity.carrier);
    params.append(entity.dispatched_at);
    tx.exec_params(kUpdate, params);
}

auto DeliveryUnitRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace cargo_decomposition
