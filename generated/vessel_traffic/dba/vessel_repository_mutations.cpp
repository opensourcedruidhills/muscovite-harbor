// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace vessel_traffic {

auto VesselRepositoryImpl::insert(pqxx::work& tx, const Vessel& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.id,
        entity.imo_number,
        entity.mmsi,
        entity.call_sign,
        entity.name,
        entity.vessel_type,
        entity.flag_state,
        entity.is_active,
    );
}

auto VesselRepositoryImpl::update(pqxx::work& tx, const Vessel& entity) -> void {
    // field params reuse same order as kUpdate (SET ... WHERE id = $N+1)
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.id);
    params.append(entity.imo_number);
    params.append(entity.mmsi);
    params.append(entity.call_sign);
    params.append(entity.name);
    params.append(entity.vessel_type);
    params.append(entity.flag_state);
    params.append(entity.is_active);
    tx.exec_params(kUpdate, params);
}

auto VesselRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace vessel_traffic
