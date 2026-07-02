#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "chassis_unit.hpp"
#include "intermodal_transfer_queries.hpp"
#include <algorithm>
#include <iterator>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>

namespace intermodal_transfer {

class DbaOperationSpan {
public:
    explicit DbaOperationSpan(std::string_view operation) : operation_{operation} {}
    auto set_status_ok() noexcept -> void {}
    auto set_error(std::string_view /*message*/) noexcept -> void {}
private:
    std::string_view operation_;
};

/// Concrete CRTP repository implementation for ChassisUnit.
/// Satisfies RepositoryBase<ChassisUnitRepositoryImpl<C>, ChassisUnit> contract.
/// Uses embedded SQL constants from intermodal_transfer_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class ChassisUnitRepositoryImpl {
public:
    explicit ChassisUnitRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const ChassisUnit& entity) -> void {
        DbaOperationSpan span("ChassisUnitRepositoryImpl::save");
        auto tx = conn_.begin();
        tx.exec_params(queries::ChassisUnitInsert, entity.id, entity.chassis_number, entity.chassis_type, entity.is_available);
        tx.commit();
        span.set_status_ok();
    }

    auto update(const ChassisUnit& entity) -> void {
        DbaOperationSpan span("ChassisUnitRepositoryImpl::update");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::ChassisUnitUpdate, entity.id, entity.chassis_number, entity.chassis_type, entity.is_available);
        if (result.affected_rows() == 0) {
            span.set_error("not found");
            throw std::runtime_error("ChassisUnit not found: " + entity.id);
        }
        tx.commit();
        span.set_status_ok();
    }

    auto remove(const std::string& id) -> void {
        DbaOperationSpan span("ChassisUnitRepositoryImpl::remove");
        auto tx = conn_.begin();
        tx.exec_params(queries::ChassisUnitDelete, id);
        tx.commit();
        span.set_status_ok();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<ChassisUnit> {
        DbaOperationSpan span("ChassisUnitRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::ChassisUnitSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        auto mapped = map_row(result[0]);
        span.set_status_ok();
        return mapped;
    }

    [[nodiscard]] auto find_all() -> std::vector<ChassisUnit> {
        DbaOperationSpan span("ChassisUnitRepositoryImpl::find_all");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::ChassisUnitSelectAll);
        tx.commit();
        auto out = std::vector<ChassisUnit>{ };
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        span.set_status_ok();
        return out;
    }

    /// Filter all entities by a domain specification (in-memory).
    template<typename Spec>
    [[nodiscard]] auto filter_by_spec(const Spec& spec) const -> std::vector<ChassisUnit> {
        auto all = find_all();
        auto result = std::vector<ChassisUnit>{};
        std::copy_if(all.begin(), all.end(), std::back_inserter(result),
                     [&spec](const ChassisUnit& e) { return spec.is_satisfied_by(e); });
        return result;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> ChassisUnit {
        return ChassisUnit{
            .id = row[0].as<std::string>(),
            .chassis_number = row[1].as<std::string>(),
            .chassis_type = row[2].as<std::string>(),
            .is_available = row[3].as<bool>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace intermodal_transfer
