// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace passenger_terminal {

auto PassengerRepositoryImpl::insert(pqxx::work& tx, const Passenger& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.id,
        entity.booking_ref,
        entity.passenger_type,
        entity.voyage_id,
        entity.status,
    );
}

auto PassengerRepositoryImpl::update(pqxx::work& tx, const Passenger& entity) -> void {
    // field params reuse same order as kUpdate (SET ... WHERE id = $N+1)
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.id);
    params.append(entity.booking_ref);
    params.append(entity.passenger_type);
    params.append(entity.voyage_id);
    params.append(entity.status);
    tx.exec_params(kUpdate, params);
}

auto PassengerRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace passenger_terminal
