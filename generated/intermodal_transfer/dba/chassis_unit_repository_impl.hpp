#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "chassis_unit.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace intermodal_transfer {

/// Concrete CRTP repository implementation for ChassisUnit.
/// Satisfies RepositoryBase<ChassisUnitRepositoryImpl<C>, ChassisUnit> contract.
/// Uses parameterised SQL (pqxx) — no stored procedures (ADR 20260120).
template<typename Connection>
class ChassisUnitRepositoryImpl {
public:
    explicit ChassisUnitRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto build_select_by_id_query() const -> std::string {
        return "SELECT id, id, chassis_number, chassis_type, is_available FROM intermodal_transfer.chassis_unit WHERE id = $1";
    }

    [[nodiscard]] auto build_insert_query() const -> std::string {
        return "INSERT INTO intermodal_transfer.chassis_unit (id, id, chassis_number, chassis_type, is_available) VALUES ($1, $2, $3, $4, $5) RETURNING id";
    }

    [[nodiscard]] auto build_update_query() const -> std::string {
        return "UPDATE intermodal_transfer.chassis_unit SET id = $2, chassis_number = $3, chassis_type = $4, is_available = $5 WHERE id = $1";
    }

    [[nodiscard]] auto build_delete_query() const -> std::string {
        return "DELETE FROM intermodal_transfer.chassis_unit WHERE id = $1";
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> ChassisUnit {
        return ChassisUnit{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .chassis_number = row[2].as<std::string>(),
            .chassis_type = row[3].as<std::string>(),
            .is_available = row[4].as<std::string>(),
        };
    }

    auto save(const ChassisUnit& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_insert_query(), entity.id, entity.id, entity.chassis_number, entity.chassis_type, entity.is_available);
        tx.commit();
    }

    auto update(const ChassisUnit& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_update_query(), entity.id, entity.id, entity.chassis_number, entity.chassis_type, entity.is_available);
        if (result.affected_rows() == 0) {
            throw std::runtime_error("ChassisUnit not found: " + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_delete_query(), id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<ChassisUnit> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_select_by_id_query(), id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

private:
    Connection& conn_;
};

} // namespace intermodal_transfer
