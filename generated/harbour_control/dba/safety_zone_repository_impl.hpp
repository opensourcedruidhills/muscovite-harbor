#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "safety_zone.hpp"
#include "harbour_control_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace harbour_control {

/// Concrete CRTP repository implementation for SafetyZone.
/// Satisfies RepositoryBase<SafetyZoneRepositoryImpl<C>, SafetyZone> contract.
/// Uses embedded SQL constants from harbour_control_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class SafetyZoneRepositoryImpl {
public:
    explicit SafetyZoneRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const SafetyZone& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::SafetyZoneInsert, entity.id, entity.id, entity.zone_code, entity.zone_name, entity.security_level, entity.max_hazmat_class, entity.is_restricted);
        tx.commit();
    }

    auto update(const SafetyZone& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::SafetyZoneUpdate, entity.id, entity.id, entity.zone_code, entity.zone_name, entity.security_level, entity.max_hazmat_class, entity.is_restricted);
        if (result.affected_rows() == 0) {
            throw std::runtime_error(SafetyZone not found:  + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::SafetyZoneDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<SafetyZone> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::SafetyZoneSelectById, id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<SafetyZone> {
        auto tx = conn_.begin();
        auto result = tx.exec(queries::SafetyZoneSelectAll);
        tx.commit();
        auto out = std::vector<SafetyZone>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> SafetyZone {
        return SafetyZone{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .zone_code = row[2].as<std::string>(),
            .zone_name = row[3].as<std::string>(),
            .security_level = row[4].as<std::string>(),
            .max_hazmat_class = row[5].as<std::string>(),
            .is_restricted = row[6].as<std::string>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace harbour_control
