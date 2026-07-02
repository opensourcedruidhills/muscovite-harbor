#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "pilot_assignment.hpp"
#include "vessel_traffic_queries.hpp"
#include <algorithm>
#include <iterator>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>

namespace vessel_traffic {

class DbaOperationSpan {
public:
    explicit DbaOperationSpan(std::string_view operation) : operation_{operation} {}
    auto set_status_ok() noexcept -> void {}
    auto set_error(std::string_view /*message*/) noexcept -> void {}
private:
    std::string_view operation_;
};

/// Concrete CRTP repository implementation for PilotAssignment.
/// Satisfies RepositoryBase<PilotAssignmentRepositoryImpl<C>, PilotAssignment> contract.
/// Uses embedded SQL constants from vessel_traffic_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class PilotAssignmentRepositoryImpl {
public:
    explicit PilotAssignmentRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const PilotAssignment& entity) -> void {
        DbaOperationSpan span("PilotAssignmentRepositoryImpl::save");
        auto tx = conn_.begin();
        tx.exec_params(queries::PilotAssignmentInsert, entity.id, entity.voyage_id, entity.pilot_name, entity.pilot_zone, entity.boarding_time, entity.disembark_time);
        tx.commit();
        span.set_status_ok();
    }

    auto update(const PilotAssignment& entity) -> void {
        DbaOperationSpan span("PilotAssignmentRepositoryImpl::update");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::PilotAssignmentUpdate, entity.id, entity.voyage_id, entity.pilot_name, entity.pilot_zone, entity.boarding_time, entity.disembark_time);
        if (result.affected_rows() == 0) {
            span.set_error("not found");
            throw std::runtime_error("PilotAssignment not found: " + entity.id);
        }
        tx.commit();
        span.set_status_ok();
    }

    auto remove(const std::string& id) -> void {
        DbaOperationSpan span("PilotAssignmentRepositoryImpl::remove");
        auto tx = conn_.begin();
        tx.exec_params(queries::PilotAssignmentDelete, id);
        tx.commit();
        span.set_status_ok();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<PilotAssignment> {
        DbaOperationSpan span("PilotAssignmentRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::PilotAssignmentSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        auto mapped = map_row(result[0]);
        span.set_status_ok();
        return mapped;
    }

    [[nodiscard]] auto find_all() -> std::vector<PilotAssignment> {
        DbaOperationSpan span("PilotAssignmentRepositoryImpl::find_all");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::PilotAssignmentSelectAll);
        tx.commit();
        auto out = std::vector<PilotAssignment>{ };
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        span.set_status_ok();
        return out;
    }

    /// Filter all entities by a domain specification (in-memory).
    template<typename Spec>
    [[nodiscard]] auto filter_by_spec(const Spec& spec) const -> std::vector<PilotAssignment> {
        auto all = find_all();
        auto result = std::vector<PilotAssignment>{};
        std::copy_if(all.begin(), all.end(), std::back_inserter(result),
                     [&spec](const PilotAssignment& e) { return spec.is_satisfied_by(e); });
        return result;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> PilotAssignment {
        return PilotAssignment{
            .id = row[0].as<std::string>(),
            .voyage_id = row[1].as<boost::uuids::uuid>(),
            .pilot_name = row[2].as<std::string>(),
            .pilot_zone = row[3].as<std::string>(),
            .boarding_time = row[4].as<muscovite::dba::Timestamp>(),
            .disembark_time = row[5].as<muscovite::dba::Timestamp>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace vessel_traffic
