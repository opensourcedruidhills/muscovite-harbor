#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "load_plan_query_repository.hpp"
#include <cstdint>
#include <optional>
#include <stdexcept>
#include <string>
#include <vector>

namespace cargo_operations {

/// pqxx-based query repository implementation for LoadPlan aggregate.
/// Uses direct parameterised SQL — no stored procedures (ADR 20260120).
template<typename Connection>
class LoadPlanQueryRepositoryImpl : public LoadPlanQueryRepository {
public:
    explicit LoadPlanQueryRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto find_by_id(const LoadPlan::Id& id) -> std::optional<LoadPlan> override {
        auto tx = conn_.begin();
        auto result = tx.exec_params("SELECT id, id, voyage_id, created_at, status FROM cargo_operations.load_plan WHERE id = $1", id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<LoadPlan> override {
        auto tx = conn_.begin();
        auto result = tx.exec("SELECT id, id, voyage_id, created_at, status FROM cargo_operations.load_plan ORDER BY id");
        tx.commit();
        auto out = std::vector<LoadPlan>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
    }

    [[nodiscard]] auto count() -> std::int64_t override {
        auto tx = conn_.begin();
        auto result = tx.exec("SELECT COUNT(*) FROM cargo_operations.load_plan");
        tx.commit();
        return result[0][0].as<std::int64_t>();
    }

private:
    Connection& conn_;

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> LoadPlan {
        return LoadPlan{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .voyage_id = row[2].as<std::string>(),
            .created_at = row[3].as<std::string>(),
            .status = row[4].as<std::string>(),
        };
    }
};

} // namespace cargo_operations
