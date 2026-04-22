#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "discharge_sequence.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace cargo_operations {

/// Concrete CRTP repository implementation for DischargeSequence.
/// Satisfies RepositoryBase<DischargeSequenceRepositoryImpl<C>, DischargeSequence> contract.
/// Uses parameterised SQL (pqxx) — no stored procedures (ADR 20260120).
template<typename Connection>
class DischargeSequenceRepositoryImpl {
public:
    explicit DischargeSequenceRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto build_select_by_id_query() const -> std::string {
        return "SELECT id, id, load_plan_id, container_id, sequence_order, crane_id FROM cargo_operations.discharge_sequence WHERE id = $1";
    }

    [[nodiscard]] auto build_insert_query() const -> std::string {
        return "INSERT INTO cargo_operations.discharge_sequence (id, id, load_plan_id, container_id, sequence_order, crane_id) VALUES ($1, $2, $3, $4, $5, $6) RETURNING id";
    }

    [[nodiscard]] auto build_update_query() const -> std::string {
        return "UPDATE cargo_operations.discharge_sequence SET id = $2, load_plan_id = $3, container_id = $4, sequence_order = $5, crane_id = $6 WHERE id = $1";
    }

    [[nodiscard]] auto build_delete_query() const -> std::string {
        return "DELETE FROM cargo_operations.discharge_sequence WHERE id = $1";
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> DischargeSequence {
        return DischargeSequence{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .load_plan_id = row[2].as<std::string>(),
            .container_id = row[3].as<std::string>(),
            .sequence_order = row[4].as<std::string>(),
            .crane_id = row[5].as<std::string>(),
        };
    }

    auto save(const DischargeSequence& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_insert_query(), entity.id, entity.id, entity.load_plan_id, entity.container_id, entity.sequence_order, entity.crane_id);
        tx.commit();
    }

    auto update(const DischargeSequence& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_update_query(), entity.id, entity.id, entity.load_plan_id, entity.container_id, entity.sequence_order, entity.crane_id);
        if (result.affected_rows() == 0) {
            throw std::runtime_error("DischargeSequence not found: " + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_delete_query(), id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<DischargeSequence> {
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
