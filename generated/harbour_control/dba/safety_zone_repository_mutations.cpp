// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "safety_zone_repository_mutations.hpp"
#include <pqxx/pqxx>
#include <stdexcept>

namespace harbour_control {

auto SafetyZoneRepositoryImpl::insert(pqxx::work& tx, const SafetyZone& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.zone_code,
        entity.zone_name,
        entity.security_level,
        entity.max_hazmat_class,
        entity.is_restricted);
}

auto SafetyZoneRepositoryImpl::update(pqxx::work& tx, const SafetyZone& entity) -> void {
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.zone_code);
    params.append(entity.zone_name);
    params.append(entity.security_level);
    params.append(entity.max_hazmat_class);
    params.append(entity.is_restricted);
    tx.exec_params(kUpdate, params);
}

auto SafetyZoneRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace harbour_control
