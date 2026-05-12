#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "load_plan_command_repository.hpp"
#include "cargo_operations_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace cargo_operations {

/// pqxx-based command repository implementation for LoadPlan aggregate.
/// Uses embedded SQL constants from cargo_operations_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class LoadPlanCommandRepositoryImpl : public LoadPlanCommandRepository {
public:
    explicit LoadPlanCommandRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const LoadPlan& entity) -> void override {
        auto tx = conn_.begin();
        tx.exec_params(queries::LoadPlanUpsert,
            entity.id, entity.id, entity.voyage_id, entity.created_at, entity.status);
        tx.commit();
    }

    auto remove(const LoadPlan::Id& id) -> void override {
        auto tx = conn_.begin();
        tx.exec_params(queries::LoadPlanDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const LoadPlan::Id& id) -> std::optional<LoadPlan> override {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::LoadPlanSelectById, id);
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
;

} // namespace cargo_operations
