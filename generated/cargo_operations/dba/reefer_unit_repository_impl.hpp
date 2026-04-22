#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "reefer_unit.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace cargo_operations {

/// Concrete CRTP repository implementation for ReeferUnit.
/// Satisfies RepositoryBase<ReeferUnitRepositoryImpl<C>, ReeferUnit> contract.
/// Uses parameterised SQL (pqxx) — no stored procedures (ADR 20260120).
template<typename Connection>
class ReeferUnitRepositoryImpl {
public:
    explicit ReeferUnitRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto build_select_by_id_query() const -> std::string {
        return "SELECT id, id, container_id, target_temp_c, current_temp_c, is_powered FROM cargo_operations.reefer_unit WHERE id = $1";
    }

    [[nodiscard]] auto build_insert_query() const -> std::string {
        return "INSERT INTO cargo_operations.reefer_unit (id, id, container_id, target_temp_c, current_temp_c, is_powered) VALUES ($1, $2, $3, $4, $5, $6) RETURNING id";
    }

    [[nodiscard]] auto build_update_query() const -> std::string {
        return "UPDATE cargo_operations.reefer_unit SET id = $2, container_id = $3, target_temp_c = $4, current_temp_c = $5, is_powered = $6 WHERE id = $1";
    }

    [[nodiscard]] auto build_delete_query() const -> std::string {
        return "DELETE FROM cargo_operations.reefer_unit WHERE id = $1";
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> ReeferUnit {
        return ReeferUnit{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .container_id = row[2].as<std::string>(),
            .target_temp_c = row[3].as<std::string>(),
            .current_temp_c = row[4].as<std::string>(),
            .is_powered = row[5].as<std::string>(),
        };
    }

    auto save(const ReeferUnit& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_insert_query(), entity.id, entity.id, entity.container_id, entity.target_temp_c, entity.current_temp_c, entity.is_powered);
        tx.commit();
    }

    auto update(const ReeferUnit& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_update_query(), entity.id, entity.id, entity.container_id, entity.target_temp_c, entity.current_temp_c, entity.is_powered);
        if (result.affected_rows() == 0) {
            throw std::runtime_error("ReeferUnit not found: " + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_delete_query(), id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<ReeferUnit> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_select_by_id_query(), id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

private:
    Connection& conn_;
};

} // namespace cargo_operations
