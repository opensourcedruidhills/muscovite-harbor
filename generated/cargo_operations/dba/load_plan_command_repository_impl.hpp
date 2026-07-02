#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "load_plan_command_repository.hpp"
#include "cargo_operations_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>

namespace cargo_operations {

class DbaOperationSpan {
public:
    explicit DbaOperationSpan(std::string_view operation) : operation_{operation} {}
    auto set_status_ok() noexcept -> void {}
    auto set_error(std::string_view /*message*/) noexcept -> void {}
private:
    std::string_view operation_;
};

/// pqxx-based command repository implementation for LoadPlan aggregate.
/// Uses embedded SQL constants from cargo_operations_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class LoadPlanCommandRepositoryImpl : public LoadPlanCommandRepository {
public:
    explicit LoadPlanCommandRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const LoadPlan& entity) -> void override {
        DbaOperationSpan span("LoadPlanCommandRepositoryImpl::save");
        auto tx = conn_.begin();
        tx.exec_params(queries::LoadPlanUpsert,
            entity.id, entity.voyage_id, entity.created_at, entity.status);
        tx.commit();
        span.set_status_ok();
    }

    auto update(const LoadPlan& entity) -> void override {
        DbaOperationSpan span("LoadPlanCommandRepositoryImpl::update");
        auto tx = conn_.begin();
        tx.exec_params(queries::LoadPlanUpdate,
            entity.id, entity.voyage_id, entity.created_at, entity.status);
        tx.commit();
        span.set_status_ok();
    }

    auto remove(const LoadPlan::Id& id) -> void override {
        DbaOperationSpan span("LoadPlanCommandRepositoryImpl::remove");
        auto tx = conn_.begin();
        tx.exec_params(queries::LoadPlanDelete, id);
        tx.commit();
        span.set_status_ok();
    }

    [[nodiscard]] auto find_by_id(const LoadPlan::Id& id) -> std::optional<LoadPlan> override {
        DbaOperationSpan span("LoadPlanCommandRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::LoadPlanSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        const auto& row = result[0];
        auto entity = LoadPlan{
            .id = row[0].as<std::string>(),
            .voyage_id = row[1].as<boost::uuids::uuid>(),
            .created_at = row[2].as<muscovite::dba::Timestamp>(),
            .status = row[3].as<std::string>(),
        };
        span.set_status_ok();
        return entity;
    }

private:
    Connection& conn_;
;

} // namespace cargo_operations
