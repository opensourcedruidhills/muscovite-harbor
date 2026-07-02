// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "barge_booking_repository_mutations.hpp"
#include <pqxx/pqxx>
#include <stdexcept>

namespace intermodal_transfer {

auto BargeBookingRepositoryImpl::insert(pqxx::work& tx, const BargeBooking& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.barge_name,
        entity.capacity_teu,
        entity.departure_at,
        entity.status);
}

auto BargeBookingRepositoryImpl::update(pqxx::work& tx, const BargeBooking& entity) -> void {
    auto params = pqxx::params{};
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
