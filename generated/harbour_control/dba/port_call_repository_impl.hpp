#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "port_call.hpp"
#include "harbour_control_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace harbour_control {

/// Concrete CRTP repository implementation for PortCall.
/// Satisfies RepositoryBase<PortCallRepositoryImpl<C>, PortCall> contract.
/// Uses embedded SQL constants from harbour_control_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class PortCallRepositoryImpl {
public:
    explicit PortCallRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const PortCall& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::PortCallInsert, entity.id, entity.id, entity.vessel_name, entity.imo_number, entity.berth_code, entity.arrival_time, entity.departure_time, entity.container_count, entity.hazmat_permits, entity.total_billed);
        tx.commit();
    }

    auto update(const PortCall& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::PortCallUpdate, entity.id, entity.id, entity.vessel_name, entity.imo_number, entity.berth_code, entity.arrival_time, entity.departure_time, entity.container_count, entity.hazmat_permits, entity.total_billed);
        if (result.affected_rows() == 0) {
            throw std::runtime_error(PortCall not found:  + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::PortCallDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<PortCall> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::PortCallSelectById, id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<PortCall> {
        auto tx = conn_.begin();
        auto result = tx.exec(queries::PortCallSelectAll);
        tx.commit();
        auto out = std::vector<PortCall>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
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

private:
    Connection& conn_;
;

} // namespace harbour_control
