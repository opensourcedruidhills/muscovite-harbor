#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "crane.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace cargo_operations {

/// Concrete CRTP repository implementation for Crane.
/// Satisfies RepositoryBase<CraneRepositoryImpl<C>, Crane> contract.
/// Uses parameterised SQL (pqxx) — no stored procedures (ADR 20260120).
template<typename Connection>
class CraneRepositoryImpl {
public:
    explicit CraneRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto build_select_by_id_query() const -> std::string {
        return "SELECT id, id, name, crane_type, max_lift_kg, is_active FROM cargo_operations.crane WHERE id = $1";
    }

    [[nodiscard]] auto build_insert_query() const -> std::string {
        return "INSERT INTO cargo_operations.crane (id, id, name, crane_type, max_lift_kg, is_active) VALUES ($1, $2, $3, $4, $5, $6) RETURNING id";
    }

    [[nodiscard]] auto build_update_query() const -> std::string {
        return "UPDATE cargo_operations.crane SET id = $2, name = $3, crane_type = $4, max_lift_kg = $5, is_active = $6 WHERE id = $1";
    }

    [[nodiscard]] auto build_delete_query() const -> std::string {
        return "DELETE FROM cargo_operations.crane WHERE id = $1";
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> Crane {
        return Crane{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .name = row[2].as<std::string>(),
            .crane_type = row[3].as<std::string>(),
            .max_lift_kg = row[4].as<std::string>(),
            .is_active = row[5].as<std::string>(),
        };
    }

    auto save(const Crane& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_insert_query(), entity.id, entity.id, entity.name, entity.crane_type, entity.max_lift_kg, entity.is_active);
        tx.commit();
    }

    auto update(const Crane& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_update_query(), entity.id, entity.id, entity.name, entity.crane_type, entity.max_lift_kg, entity.is_active);
        if (result.affected_rows() == 0) {
            throw std::runtime_error("Crane not found: " + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_delete_query(), id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<Crane> {
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
