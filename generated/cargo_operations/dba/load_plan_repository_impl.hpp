#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "load_plan.hpp"
#include "cargo_operations_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace cargo_operations {

/// Concrete CRTP repository implementation for LoadPlan.
/// Satisfies RepositoryBase<LoadPlanRepositoryImpl<C>, LoadPlan> contract.
/// Uses embedded SQL constants from cargo_operations_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class LoadPlanRepositoryImpl {
public:
    explicit LoadPlanRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const LoadPlan& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::LoadPlanInsert, entity.id, entity.id, entity.voyage_id, entity.created_at, entity.status);
        tx.commit();
    }

    auto update(const LoadPlan& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::LoadPlanUpdate, entity.id, entity.id, entity.voyage_id, entity.created_at, entity.status);
        if (result.affected_rows() == 0) {
            throw std::runtime_error(LoadPlan not found:  + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::LoadPlanDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<LoadPlan> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::LoadPlanSelectById, id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<LoadPlan> {
        auto tx = conn_.begin();
        auto result = tx.exec(queries::LoadPlanSelectAll);
        tx.commit();
        auto out = std::vector<LoadPlan>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> LoadPlan {
        return LoadPlan{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .voyage_id = row[2].as<std::string>(),
            .created_at = row[3].as<std::string>(),
            .status = row[4].as<std::string>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace cargo_operations
