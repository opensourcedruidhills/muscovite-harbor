// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "voyage_repository_mutations.hpp"
#include <pqxx/pqxx>
#include <stdexcept>

namespace vessel_traffic {

auto VoyageRepositoryImpl::insert(pqxx::work& tx, const Voyage& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.vessel_id,
        entity.berth_id,
        entity.voyage_number,
        entity.eta,
        entity.ata,
        entity.etd,
        entity.atd,
        entity.cargo_category,
        entity.status);
}

auto VoyageRepositoryImpl::update(pqxx::work& tx, const Voyage& entity) -> void {
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.vessel_id);
    params.append(entity.berth_id);
    params.append(entity.voyage_number);
    params.append(entity.eta);
    params.append(entity.ata);
    params.append(entity.etd);
    params.append(entity.atd);
    params.append(entity.cargo_category);
    params.append(entity.status);
    tx.exec_params(kUpdate, params);
}

auto VoyageRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace vessel_traffic
