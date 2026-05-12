// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace vessel_traffic {

auto TugBookingRepositoryImpl::insert(pqxx::work& tx, const TugBooking& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.id,
        entity.voyage_id,
        entity.tug_name,
        entity.bollard_pull_t,
        entity.is_confirmed,
    );
}

auto TugBookingRepositoryImpl::update(pqxx::work& tx, const TugBooking& entity) -> void {
    // field params reuse same order as kUpdate (SET ... WHERE id = $N+1)
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.id);
    params.append(entity.voyage_id);
    params.append(entity.tug_name);
    params.append(entity.bollard_pull_t);
    params.append(entity.is_confirmed);
    tx.exec_params(kUpdate, params);
}

auto TugBookingRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace vessel_traffic
