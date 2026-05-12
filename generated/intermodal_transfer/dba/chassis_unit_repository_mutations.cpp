// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace intermodal_transfer {

auto ChassisUnitRepositoryImpl::insert(pqxx::work& tx, const ChassisUnit& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.id,
        entity.chassis_number,
        entity.chassis_type,
        entity.is_available,
    );
}

auto ChassisUnitRepositoryImpl::update(pqxx::work& tx, const ChassisUnit& entity) -> void {
    // field params reuse same order as kUpdate (SET ... WHERE id = $N+1)
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.id);
    params.append(entity.chassis_number);
    params.append(entity.chassis_type);
    params.append(entity.is_available);
    tx.exec_params(kUpdate, params);
}

auto ChassisUnitRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace intermodal_transfer
