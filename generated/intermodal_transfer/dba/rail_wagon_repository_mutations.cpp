// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "rail_wagon_repository_mutations.hpp"
#include <pqxx/pqxx>
#include <stdexcept>

namespace intermodal_transfer {

auto RailWagonRepositoryImpl::insert(pqxx::work& tx, const RailWagon& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.wagon_number,
        entity.max_weight_kg,
        entity.slot_id);
}

auto RailWagonRepositoryImpl::update(pqxx::work& tx, const RailWagon& entity) -> void {
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.wagon_number);
    params.append(entity.max_weight_kg);
    params.append(entity.slot_id);
    tx.exec_params(kUpdate, params);
}

auto RailWagonRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace intermodal_transfer
