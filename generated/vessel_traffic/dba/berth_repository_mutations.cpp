// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace vessel_traffic {

auto BerthRepositoryImpl::insert(pqxx::work& tx, const Berth& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.id,
        entity.code,
        entity.name,
        entity.max_loa_metres,
        entity.max_draft_metres,
        entity.max_beam_metres,
        entity.has_crane_access,
        entity.has_reefer_plugs,
        entity.is_active,
    );
}

auto BerthRepositoryImpl::update(pqxx::work& tx, const Berth& entity) -> void {
    // field params reuse same order as kUpdate (SET ... WHERE id = $N+1)
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.id);
    params.append(entity.code);
    params.append(entity.name);
    params.append(entity.max_loa_metres);
    params.append(entity.max_draft_metres);
    params.append(entity.max_beam_metres);
    params.append(entity.has_crane_access);
    params.append(entity.has_reefer_plugs);
    params.append(entity.is_active);
    tx.exec_params(kUpdate, params);
}

auto BerthRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace vessel_traffic
