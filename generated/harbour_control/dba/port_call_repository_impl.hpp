#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "port_call.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace harbour_control {

/// Concrete CRTP repository implementation for PortCall.
/// Satisfies RepositoryBase<PortCallRepositoryImpl<C>, PortCall> contract.
/// Uses parameterised SQL (pqxx) — no stored procedures (ADR 20260120).
template<typename Connection>
class PortCallRepositoryImpl {
public:
    explicit PortCallRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto build_select_by_id_query() const -> std::string {
        return "SELECT id, id, vessel_name, imo_number, berth_code, arrival_time, departure_time, container_count, hazmat_permits, total_billed FROM harbour_control.port_call WHERE id = $1";
    }

    [[nodiscard]] auto build_insert_query() const -> std::string {
        return "INSERT INTO harbour_control.port_call (id, id, vessel_name, imo_number, berth_code, arrival_time, departure_time, container_count, hazmat_permits, total_billed) VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10) RETURNING id";
    }

    [[nodiscard]] auto build_update_query() const -> std::string {
        return "UPDATE harbour_control.port_call SET id = $2, vessel_name = $3, imo_number = $4, berth_code = $5, arrival_time = $6, departure_time = $7, container_count = $8, hazmat_permits = $9, total_billed = $10 WHERE id = $1";
    }

    [[nodiscard]] auto build_delete_query() const -> std::string {
        return "DELETE FROM harbour_control.port_call WHERE id = $1";
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> PortCall {
        return PortCall{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .vessel_name = row[2].as<std::string>(),
            .imo_number = row[3].as<std::string>(),
            .berth_code = row[4].as<std::string>(),
            .arrival_time = row[5].as<std::string>(),
            .departure_time = row[6].as<std::string>(),
            .container_count = row[7].as<std::string>(),
            .hazmat_permits = row[8].as<std::string>(),
            .total_billed = row[9].as<std::string>(),
        };
    }

    auto save(const PortCall& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_insert_query(), entity.id, entity.id, entity.vessel_name, entity.imo_number, entity.berth_code, entity.arrival_time, entity.departure_time, entity.container_count, entity.hazmat_permits, entity.total_billed);
        tx.commit();
    }

    auto update(const PortCall& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_update_query(), entity.id, entity.id, entity.vessel_name, entity.imo_number, entity.berth_code, entity.arrival_time, entity.departure_time, entity.container_count, entity.hazmat_permits, entity.total_billed);
        if (result.affected_rows() == 0) {
            throw std::runtime_error("PortCall not found: " + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_delete_query(), id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<PortCall> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_select_by_id_query(), id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

private:
    Connection& conn_;
};

} // namespace harbour_control
