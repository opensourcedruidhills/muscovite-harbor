// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace passenger_terminal {

auto BoardingPassRepositoryImpl::insert(pqxx::work& tx, const BoardingPass& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.id,
        entity.passenger_id,
        entity.gate_id,
        entity.boarding_group,
        entity.seat_number,
        entity.issued_at,
        entity.scanned_at,
    );
}

auto BoardingPassRepositoryImpl::update(pqxx::work& tx, const BoardingPass& entity) -> void {
    // field params reuse same order as kUpdate (SET ... WHERE id = $N+1)
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.id);
    params.append(entity.passenger_id);
    params.append(entity.gate_id);
    params.append(entity.boarding_group);
    params.append(entity.seat_number);
    params.append(entity.issued_at);
    params.append(entity.scanned_at);
    tx.exec_params(kUpdate, params);
}

auto BoardingPassRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace passenger_terminal
