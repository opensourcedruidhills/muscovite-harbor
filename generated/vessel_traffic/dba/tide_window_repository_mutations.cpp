// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace vessel_traffic {

auto TideWindowRepositoryImpl::insert(pqxx::work& tx, const TideWindow& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.id,
        entity.berth_id,
        entity.tide_height_metres,
        entity.available_draft,
    );
}

auto TideWindowRepositoryImpl::update(pqxx::work& tx, const TideWindow& entity) -> void {
    // field params reuse same order as kUpdate (SET ... WHERE id = $N+1)
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.id);
    params.append(entity.berth_id);
    params.append(entity.tide_height_metres);
    params.append(entity.available_draft);
    tx.exec_params(kUpdate, params);
}

auto TideWindowRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace vessel_traffic
