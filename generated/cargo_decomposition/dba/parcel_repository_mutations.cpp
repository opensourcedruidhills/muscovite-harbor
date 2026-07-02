// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "parcel_repository_mutations.hpp"
#include <pqxx/pqxx>
#include <stdexcept>

namespace cargo_decomposition {

auto ParcelRepositoryImpl::insert(pqxx::work& tx, const Parcel& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.tracking_number,
        entity.pallet_id,
        entity.weight_kg,
        entity.hs_code,
        entity.description);
}

auto ParcelRepositoryImpl::update(pqxx::work& tx, const Parcel& entity) -> void {
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.tracking_number);
    params.append(entity.pallet_id);
    params.append(entity.weight_kg);
    params.append(entity.hs_code);
    params.append(entity.description);
    tx.exec_params(kUpdate, params);
}

auto ParcelRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace cargo_decomposition
