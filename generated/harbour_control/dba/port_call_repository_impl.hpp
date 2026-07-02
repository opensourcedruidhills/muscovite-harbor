#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "port_call.hpp"
#include "harbour_control_queries.hpp"
#include <algorithm>
#include <iterator>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>

namespace harbour_control {

class DbaOperationSpan {
public:
    explicit DbaOperationSpan(std::string_view operation) : operation_{operation} {}
    auto set_status_ok() noexcept -> void {}
    auto set_error(std::string_view /*message*/) noexcept -> void {}
private:
    std::string_view operation_;
};

/// Concrete CRTP repository implementation for PortCall.
/// Satisfies RepositoryBase<PortCallRepositoryImpl<C>, PortCall> contract.
/// Uses embedded SQL constants from harbour_control_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class PortCallRepositoryImpl {
public:
    explicit PortCallRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const PortCall& entity) -> void {
        DbaOperationSpan span("PortCallRepositoryImpl::save");
        auto tx = conn_.begin();
        tx.exec_params(queries::PortCallInsert, entity.id, entity.vessel_name, entity.imo_number, entity.berth_code, entity.arrival_time, entity.departure_time, entity.container_count, entity.hazmat_permits, entity.total_billed);
        tx.commit();
        span.set_status_ok();
    }

    auto update(const PortCall& entity) -> void {
        DbaOperationSpan span("PortCallRepositoryImpl::update");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::PortCallUpdate, entity.id, entity.vessel_name, entity.imo_number, entity.berth_code, entity.arrival_time, entity.departure_time, entity.container_count, entity.hazmat_permits, entity.total_billed);
        if (result.affected_rows() == 0) {
            span.set_error("not found");
            throw std::runtime_error("PortCall not found: " + entity.id);
        }
        tx.commit();
        span.set_status_ok();
    }

    auto remove(const std::string& id) -> void {
        DbaOperationSpan span("PortCallRepositoryImpl::remove");
        auto tx = conn_.begin();
        tx.exec_params(queries::PortCallDelete, id);
        tx.commit();
        span.set_status_ok();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<PortCall> {
        DbaOperationSpan span("PortCallRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::PortCallSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        auto mapped = map_row(result[0]);
        span.set_status_ok();
        return mapped;
    }

    [[nodiscard]] auto find_all() -> std::vector<PortCall> {
        DbaOperationSpan span("PortCallRepositoryImpl::find_all");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::PortCallSelectAll);
        tx.commit();
        auto out = std::vector<PortCall>{ };
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        span.set_status_ok();
        return out;
    }

    /// Filter all entities by a domain specification (in-memory).
    template<typename Spec>
    [[nodiscard]] auto filter_by_spec(const Spec& spec) const -> std::vector<PortCall> {
        auto all = find_all();
        auto result = std::vector<PortCall>{};
        std::copy_if(all.begin(), all.end(), std::back_inserter(result),
                     [&spec](const PortCall& e) { return spec.is_satisfied_by(e); });
        return result;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> PortCall {
        return PortCall{
            .id = row[0].as<std::string>(),
            .vessel_name = row[1].as<std::string>(),
            .imo_number = row[2].as<std::string>(),
            .berth_code = row[3].as<std::string>(),
            .arrival_time = row[4].as<muscovite::dba::Timestamp>(),
            .departure_time = row[5].as<muscovite::dba::Timestamp>(),
            .container_count = row[6].as<std::int32_t>(),
            .hazmat_permits = row[7].as<std::int32_t>(),
            .total_billed = row[8].as<muscovite::dba::Decimal>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace harbour_control
