#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "safety_zone.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace harbour_control {

/// Concrete CRTP repository implementation for SafetyZone.
/// Satisfies RepositoryBase<SafetyZoneRepositoryImpl<C>, SafetyZone> contract.
/// Uses parameterised SQL (pqxx) — no stored procedures (ADR 20260120).
template<typename Connection>
class SafetyZoneRepositoryImpl {
public:
    explicit SafetyZoneRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto build_select_by_id_query() const -> std::string {
        return "SELECT id, id, zone_code, zone_name, security_level, max_hazmat_class, is_restricted FROM harbour_control.safety_zone WHERE id = $1";
    }

    [[nodiscard]] auto build_insert_query() const -> std::string {
        return "INSERT INTO harbour_control.safety_zone (id, id, zone_code, zone_name, security_level, max_hazmat_class, is_restricted) VALUES ($1, $2, $3, $4, $5, $6, $7) RETURNING id";
    }

    [[nodiscard]] auto build_update_query() const -> std::string {
        return "UPDATE harbour_control.safety_zone SET id = $2, zone_code = $3, zone_name = $4, security_level = $5, max_hazmat_class = $6, is_restricted = $7 WHERE id = $1";
    }

    [[nodiscard]] auto build_delete_query() const -> std::string {
        return "DELETE FROM harbour_control.safety_zone WHERE id = $1";
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

    auto save(const SafetyZone& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_insert_query(), entity.id, entity.id, entity.zone_code, entity.zone_name, entity.security_level, entity.max_hazmat_class, entity.is_restricted);
        tx.commit();
    }

    auto update(const SafetyZone& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_update_query(), entity.id, entity.id, entity.zone_code, entity.zone_name, entity.security_level, entity.max_hazmat_class, entity.is_restricted);
        if (result.affected_rows() == 0) {
            throw std::runtime_error("SafetyZone not found: " + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_delete_query(), id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<SafetyZone> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_select_by_id_query(), id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

private:
    Connection& conn_;
};

} // namespace harbour_control
