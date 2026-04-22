#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "yard_slot.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace cargo_operations {

/// Concrete CRTP repository implementation for YardSlot.
/// Satisfies RepositoryBase<YardSlotRepositoryImpl<C>, YardSlot> contract.
/// Uses parameterised SQL (pqxx) — no stored procedures (ADR 20260120).
template<typename Connection>
class YardSlotRepositoryImpl {
public:
    explicit YardSlotRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto build_select_by_id_query() const -> std::string {
        return "SELECT id, id, code, max_weight_kg, max_tier, has_power, is_occupied FROM cargo_operations.yard_slot WHERE id = $1";
    }

    [[nodiscard]] auto build_insert_query() const -> std::string {
        return "INSERT INTO cargo_operations.yard_slot (id, id, code, max_weight_kg, max_tier, has_power, is_occupied) VALUES ($1, $2, $3, $4, $5, $6, $7) RETURNING id";
    }

    [[nodiscard]] auto build_update_query() const -> std::string {
        return "UPDATE cargo_operations.yard_slot SET id = $2, code = $3, max_weight_kg = $4, max_tier = $5, has_power = $6, is_occupied = $7 WHERE id = $1";
    }

    [[nodiscard]] auto build_delete_query() const -> std::string {
        return "DELETE FROM cargo_operations.yard_slot WHERE id = $1";
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> YardSlot {
        return YardSlot{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .code = row[2].as<std::string>(),
            .max_weight_kg = row[3].as<std::string>(),
            .max_tier = row[4].as<std::string>(),
            .has_power = row[5].as<std::string>(),
            .is_occupied = row[6].as<std::string>(),
        };
    }

    auto save(const YardSlot& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_insert_query(), entity.id, entity.id, entity.code, entity.max_weight_kg, entity.max_tier, entity.has_power, entity.is_occupied);
        tx.commit();
    }

    auto update(const YardSlot& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_update_query(), entity.id, entity.id, entity.code, entity.max_weight_kg, entity.max_tier, entity.has_power, entity.is_occupied);
        if (result.affected_rows() == 0) {
            throw std::runtime_error("YardSlot not found: " + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_delete_query(), id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<YardSlot> {
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
