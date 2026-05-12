#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "break_bulk_item.hpp"
#include "cargo_decomposition_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace cargo_decomposition {

/// Concrete CRTP repository implementation for BreakBulkItem.
/// Satisfies RepositoryBase<BreakBulkItemRepositoryImpl<C>, BreakBulkItem> contract.
/// Uses embedded SQL constants from cargo_decomposition_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class BreakBulkItemRepositoryImpl {
public:
    explicit BreakBulkItemRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const BreakBulkItem& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::BreakBulkItemInsert, entity.id, entity.id, entity.container_id, entity.item_type, entity.weight_kg, entity.requires_crane);
        tx.commit();
    }

    auto update(const BreakBulkItem& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::BreakBulkItemUpdate, entity.id, entity.id, entity.container_id, entity.item_type, entity.weight_kg, entity.requires_crane);
        if (result.affected_rows() == 0) {
            throw std::runtime_error(BreakBulkItem not found:  + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::BreakBulkItemDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<BreakBulkItem> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::BreakBulkItemSelectById, id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<BreakBulkItem> {
        auto tx = conn_.begin();
        auto result = tx.exec(queries::BreakBulkItemSelectAll);
        tx.commit();
        auto out = std::vector<BreakBulkItem>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
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

private:
    Connection& conn_;
;

} // namespace cargo_decomposition
