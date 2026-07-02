// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "pallet_repository_mutations.hpp"
#include <pqxx/pqxx>
#include <stdexcept>

namespace cargo_decomposition {

auto PalletRepositoryImpl::insert(pqxx::work& tx, const Pallet& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.pallet_id,
        entity.container_id,
        entity.weight_kg,
        entity.length_cm,
        entity.width_cm,
        entity.height_cm,
        entity.hs_code);
}

auto PalletRepositoryImpl::update(pqxx::work& tx, const Pallet& entity) -> void {
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.pallet_id);
    params.append(entity.container_id);
    params.append(entity.weight_kg);
    params.append(entity.length_cm);
    params.append(entity.width_cm);
    params.append(entity.height_cm);
    params.append(entity.hs_code);
    tx.exec_params(kUpdate, params);
}

auto PalletRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace cargo_decomposition
