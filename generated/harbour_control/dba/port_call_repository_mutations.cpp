// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace harbour_control {

auto PortCallRepositoryImpl::insert(pqxx::work& tx, const PortCall& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.id,
        entity.vessel_name,
        entity.imo_number,
        entity.berth_code,
        entity.arrival_time,
        entity.departure_time,
        entity.container_count,
        entity.hazmat_permits,
        entity.total_billed,
    );
}

auto PortCallRepositoryImpl::update(pqxx::work& tx, const PortCall& entity) -> void {
    // field params reuse same order as kUpdate (SET ... WHERE id = $N+1)
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.id);
    params.append(entity.vessel_name);
    params.append(entity.imo_number);
    params.append(entity.berth_code);
    params.append(entity.arrival_time);
    params.append(entity.departure_time);
    params.append(entity.container_count);
    params.append(entity.hazmat_permits);
    params.append(entity.total_billed);
    tx.exec_params(kUpdate, params);
}

auto PortCallRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace harbour_control
