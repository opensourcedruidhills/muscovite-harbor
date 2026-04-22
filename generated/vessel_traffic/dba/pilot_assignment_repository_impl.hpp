#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "pilot_assignment.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace vessel_traffic {

/// Concrete CRTP repository implementation for PilotAssignment.
/// Satisfies RepositoryBase<PilotAssignmentRepositoryImpl<C>, PilotAssignment> contract.
/// Uses parameterised SQL (pqxx) — no stored procedures (ADR 20260120).
template<typename Connection>
class PilotAssignmentRepositoryImpl {
public:
    explicit PilotAssignmentRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto build_select_by_id_query() const -> std::string {
        return "SELECT id, id, voyage_id, pilot_name, pilot_zone, boarding_time, disembark_time FROM vessel_traffic.pilot_assignment WHERE id = $1";
    }

    [[nodiscard]] auto build_insert_query() const -> std::string {
        return "INSERT INTO vessel_traffic.pilot_assignment (id, id, voyage_id, pilot_name, pilot_zone, boarding_time, disembark_time) VALUES ($1, $2, $3, $4, $5, $6, $7) RETURNING id";
    }

    [[nodiscard]] auto build_update_query() const -> std::string {
        return "UPDATE vessel_traffic.pilot_assignment SET id = $2, voyage_id = $3, pilot_name = $4, pilot_zone = $5, boarding_time = $6, disembark_time = $7 WHERE id = $1";
    }

    [[nodiscard]] auto build_delete_query() const -> std::string {
        return "DELETE FROM vessel_traffic.pilot_assignment WHERE id = $1";
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

    auto save(const PilotAssignment& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_insert_query(), entity.id, entity.id, entity.voyage_id, entity.pilot_name, entity.pilot_zone, entity.boarding_time, entity.disembark_time);
        tx.commit();
    }

    auto update(const PilotAssignment& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_update_query(), entity.id, entity.id, entity.voyage_id, entity.pilot_name, entity.pilot_zone, entity.boarding_time, entity.disembark_time);
        if (result.affected_rows() == 0) {
            throw std::runtime_error("PilotAssignment not found: " + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_delete_query(), id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<PilotAssignment> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_select_by_id_query(), id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

private:
    Connection& conn_;
};

} // namespace vessel_traffic
