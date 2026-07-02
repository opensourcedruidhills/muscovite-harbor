#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "reefer_unit.hpp"
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

/// Concrete CRTP repository implementation for ReeferUnit.
/// Satisfies RepositoryBase<ReeferUnitRepositoryImpl<C>, ReeferUnit> contract.
/// Uses embedded SQL constants from cargo_operations_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class ReeferUnitRepositoryImpl {
public:
    explicit ReeferUnitRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const ReeferUnit& entity) -> void {
        DbaOperationSpan span("ReeferUnitRepositoryImpl::save");
        auto tx = conn_.begin();
        tx.exec_params(queries::ReeferUnitInsert, entity.id, entity.container_id, entity.target_temp_c, entity.current_temp_c, entity.is_powered);
        tx.commit();
        span.set_status_ok();
    }

    auto update(const ReeferUnit& entity) -> void {
        DbaOperationSpan span("ReeferUnitRepositoryImpl::update");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::ReeferUnitUpdate, entity.id, entity.container_id, entity.target_temp_c, entity.current_temp_c, entity.is_powered);
        if (result.affected_rows() == 0) {
            span.set_error("not found");
            throw std::runtime_error("ReeferUnit not found: " + entity.id);
        }
        tx.commit();
        span.set_status_ok();
    }

    auto remove(const std::string& id) -> void {
        DbaOperationSpan span("ReeferUnitRepositoryImpl::remove");
        auto tx = conn_.begin();
        tx.exec_params(queries::ReeferUnitDelete, id);
        tx.commit();
        span.set_status_ok();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<ReeferUnit> {
        DbaOperationSpan span("ReeferUnitRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::ReeferUnitSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        auto mapped = map_row(result[0]);
        span.set_status_ok();
        return mapped;
    }

    [[nodiscard]] auto find_all() -> std::vector<ReeferUnit> {
        DbaOperationSpan span("ReeferUnitRepositoryImpl::find_all");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::ReeferUnitSelectAll);
        tx.commit();
        auto out = std::vector<ReeferUnit>{ };
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        span.set_status_ok();
        return out;
    }

    /// Filter all entities by a domain specification (in-memory).
    template<typename Spec>
    [[nodiscard]] auto filter_by_spec(const Spec& spec) const -> std::vector<ReeferUnit> {
        auto all = find_all();
        auto result = std::vector<ReeferUnit>{};
        std::copy_if(all.begin(), all.end(), std::back_inserter(result),
                     [&spec](const ReeferUnit& e) { return spec.is_satisfied_by(e); });
        return result;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> ReeferUnit {
        return ReeferUnit{
            .id = row[0].as<std::string>(),
            .container_id = row[1].as<boost::uuids::uuid>(),
            .target_temp_c = row[2].as<muscovite::dba::Decimal>(),
            .current_temp_c = row[3].as<muscovite::dba::Decimal>(),
            .is_powered = row[4].as<bool>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace cargo_operations
