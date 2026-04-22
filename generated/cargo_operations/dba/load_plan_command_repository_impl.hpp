#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "load_plan_command_repository.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace cargo_operations {

/// pqxx-based command repository implementation for LoadPlan aggregate.
/// Uses direct parameterised SQL — no stored procedures (ADR 20260120).
template<typename Connection>
class LoadPlanCommandRepositoryImpl : public LoadPlanCommandRepository {
public:
    explicit LoadPlanCommandRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const LoadPlan& entity) -> void override {
        auto tx = conn_.begin();
        tx.exec_params("INSERT INTO cargo_operations.load_plan (id, id, voyage_id, created_at, status) VALUES ($1, $2, $3, $4, $5) ON CONFLICT (id) DO UPDATE SET id = $2, voyage_id = $3, created_at = $4, status = $5",
            entity.id, entity.id, entity.voyage_id, entity.created_at, entity.status);
        tx.commit();
    }

    auto remove(const LoadPlan::Id& id) -> void override {
        auto tx = conn_.begin();
        tx.exec_params("DELETE FROM cargo_operations.load_plan WHERE id = $1", id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const LoadPlan::Id& id) -> std::optional<LoadPlan> override {
        auto tx = conn_.begin();
        auto result = tx.exec_params("SELECT id, id, voyage_id, created_at, status FROM cargo_operations.load_plan WHERE id = $1", id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        const auto& row = result[0];
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
};

} // namespace cargo_operations
