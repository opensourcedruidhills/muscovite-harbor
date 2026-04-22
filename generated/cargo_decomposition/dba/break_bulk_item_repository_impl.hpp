#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "break_bulk_item.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace cargo_decomposition {

/// Concrete CRTP repository implementation for BreakBulkItem.
/// Satisfies RepositoryBase<BreakBulkItemRepositoryImpl<C>, BreakBulkItem> contract.
/// Uses parameterised SQL (pqxx) — no stored procedures (ADR 20260120).
template<typename Connection>
class BreakBulkItemRepositoryImpl {
public:
    explicit BreakBulkItemRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto build_select_by_id_query() const -> std::string {
        return "SELECT id, id, container_id, item_type, weight_kg, requires_crane FROM cargo_decomposition.break_bulk_item WHERE id = $1";
    }

    [[nodiscard]] auto build_insert_query() const -> std::string {
        return "INSERT INTO cargo_decomposition.break_bulk_item (id, id, container_id, item_type, weight_kg, requires_crane) VALUES ($1, $2, $3, $4, $5, $6) RETURNING id";
    }

    [[nodiscard]] auto build_update_query() const -> std::string {
        return "UPDATE cargo_decomposition.break_bulk_item SET id = $2, container_id = $3, item_type = $4, weight_kg = $5, requires_crane = $6 WHERE id = $1";
    }

    [[nodiscard]] auto build_delete_query() const -> std::string {
        return "DELETE FROM cargo_decomposition.break_bulk_item WHERE id = $1";
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> BreakBulkItem {
        return BreakBulkItem{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .container_id = row[2].as<std::string>(),
            .item_type = row[3].as<std::string>(),
            .weight_kg = row[4].as<std::string>(),
            .requires_crane = row[5].as<std::string>(),
        };
    }

    auto save(const BreakBulkItem& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_insert_query(), entity.id, entity.id, entity.container_id, entity.item_type, entity.weight_kg, entity.requires_crane);
        tx.commit();
    }

    auto update(const BreakBulkItem& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_update_query(), entity.id, entity.id, entity.container_id, entity.item_type, entity.weight_kg, entity.requires_crane);
        if (result.affected_rows() == 0) {
            throw std::runtime_error("BreakBulkItem not found: " + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_delete_query(), id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<BreakBulkItem> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_select_by_id_query(), id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

private:
    Connection& conn_;
};

} // namespace cargo_decomposition
