#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "load_plan.hpp"
#include "cargo_operations_queries.hpp"
#include <algorithm>
#include <iterator>
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

/// Concrete CRTP repository implementation for LoadPlan.
/// Satisfies RepositoryBase<LoadPlanRepositoryImpl<C>, LoadPlan> contract.
/// Uses embedded SQL constants from cargo_operations_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class LoadPlanRepositoryImpl {
public:
    explicit LoadPlanRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const LoadPlan& entity) -> void {
        DbaOperationSpan span("LoadPlanRepositoryImpl::save");
        auto tx = conn_.begin();
        tx.exec_params(queries::LoadPlanInsert, entity.id, entity.voyage_id, entity.created_at, entity.status);
        tx.commit();
        span.set_status_ok();
    }

    auto update(const LoadPlan& entity) -> void {
        DbaOperationSpan span("LoadPlanRepositoryImpl::update");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::LoadPlanUpdate, entity.id, entity.voyage_id, entity.created_at, entity.status);
        if (result.affected_rows() == 0) {
            span.set_error("not found");
            throw std::runtime_error("LoadPlan not found: " + entity.id);
        }
        tx.commit();
        span.set_status_ok();
    }

    auto remove(const std::string& id) -> void {
        DbaOperationSpan span("LoadPlanRepositoryImpl::remove");
        auto tx = conn_.begin();
        tx.exec_params(queries::LoadPlanDelete, id);
        tx.commit();
        span.set_status_ok();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<LoadPlan> {
        DbaOperationSpan span("LoadPlanRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::LoadPlanSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        auto mapped = map_row(result[0]);
        span.set_status_ok();
        return mapped;
    }

    [[nodiscard]] auto find_all() -> std::vector<LoadPlan> {
        DbaOperationSpan span("LoadPlanRepositoryImpl::find_all");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::LoadPlanSelectAll);
        tx.commit();
        auto out = std::vector<LoadPlan>{ };
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        span.set_status_ok();
        return out;
    }

    /// Filter all entities by a domain specification (in-memory).
    template<typename Spec>
    [[nodiscard]] auto filter_by_spec(const Spec& spec) const -> std::vector<LoadPlan> {
        auto all = find_all();
        auto result = std::vector<LoadPlan>{};
        std::copy_if(all.begin(), all.end(), std::back_inserter(result),
                     [&spec](const LoadPlan& e) { return spec.is_satisfied_by(e); });
        return result;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> LoadPlan {
        return LoadPlan{
            .id = row[0].as<std::string>(),
            .voyage_id = row[1].as<boost::uuids::uuid>(),
            .created_at = row[2].as<muscovite::dba::Timestamp>(),
            .status = row[3].as<std::string>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace cargo_operations
