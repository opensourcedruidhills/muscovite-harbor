// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace harbour_control {

auto HazmatPermitRepositoryImpl::insert(pqxx::work& tx, const HazmatPermit& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.id,
        entity.permit_number,
        entity.vessel_id,
        entity.imo_class,
        entity.quantity_kg,
        entity.approved,
        entity.valid_from,
        entity.valid_until,
    );
}

auto HazmatPermitRepositoryImpl::update(pqxx::work& tx, const HazmatPermit& entity) -> void {
    // field params reuse same order as kUpdate (SET ... WHERE id = $N+1)
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.id);
    params.append(entity.permit_number);
    params.append(entity.vessel_id);
    params.append(entity.imo_class);
    params.append(entity.quantity_kg);
    params.append(entity.approved);
    params.append(entity.valid_from);
    params.append(entity.valid_until);
    tx.exec_params(kUpdate, params);
}

auto HazmatPermitRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace harbour_control
