#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "pilot_assignment.hpp"
#include "vessel_traffic_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace vessel_traffic {

/// Concrete CRTP repository implementation for PilotAssignment.
/// Satisfies RepositoryBase<PilotAssignmentRepositoryImpl<C>, PilotAssignment> contract.
/// Uses embedded SQL constants from vessel_traffic_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class PilotAssignmentRepositoryImpl {
public:
    explicit PilotAssignmentRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const PilotAssignment& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::PilotAssignmentInsert, entity.id, entity.id, entity.voyage_id, entity.pilot_name, entity.pilot_zone, entity.boarding_time, entity.disembark_time);
        tx.commit();
    }

    auto update(const PilotAssignment& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::PilotAssignmentUpdate, entity.id, entity.id, entity.voyage_id, entity.pilot_name, entity.pilot_zone, entity.boarding_time, entity.disembark_time);
        if (result.affected_rows() == 0) {
            throw std::runtime_error(PilotAssignment not found:  + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::PilotAssignmentDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<PilotAssignment> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::PilotAssignmentSelectById, id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<PilotAssignment> {
        auto tx = conn_.begin();
        auto result = tx.exec(queries::PilotAssignmentSelectAll);
        tx.commit();
        auto out = std::vector<PilotAssignment>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> PilotAssignment {
        return PilotAssignment{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .voyage_id = row[2].as<std::string>(),
            .pilot_name = row[3].as<std::string>(),
            .pilot_zone = row[4].as<std::string>(),
            .boarding_time = row[5].as<std::string>(),
            .disembark_time = row[6].as<std::string>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace vessel_traffic
