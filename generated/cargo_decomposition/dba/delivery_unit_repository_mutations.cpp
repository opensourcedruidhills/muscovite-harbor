// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "delivery_unit_repository_mutations.hpp"
#include <pqxx/pqxx>
#include <stdexcept>

namespace cargo_decomposition {

auto DeliveryUnitRepositoryImpl::insert(pqxx::work& tx, const DeliveryUnit& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.tracking_number,
        entity.destination,
        entity.carrier,
        entity.dispatched_at);
}

auto DeliveryUnitRepositoryImpl::update(pqxx::work& tx, const DeliveryUnit& entity) -> void {
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.tracking_number);
    params.append(entity.destination);
    params.append(entity.carrier);
    params.append(entity.dispatched_at);
    tx.exec_params(kUpdate, params);
}

auto DeliveryUnitRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace cargo_decomposition
