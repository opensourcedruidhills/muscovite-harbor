// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace intermodal_transfer {

auto BargeBookingRepositoryImpl::insert(pqxx::work& tx, const BargeBooking& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.id,
        entity.barge_name,
        entity.capacity_teu,
        entity.departure_at,
        entity.status,
    );
}

auto BargeBookingRepositoryImpl::update(pqxx::work& tx, const BargeBooking& entity) -> void {
    // field params reuse same order as kUpdate (SET ... WHERE id = $N+1)
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.id);
    params.append(entity.barge_name);
    params.append(entity.capacity_teu);
    params.append(entity.departure_at);
    params.append(entity.status);
    tx.exec_params(kUpdate, params);
}

auto BargeBookingRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace intermodal_transfer
