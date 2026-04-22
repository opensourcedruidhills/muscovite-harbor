#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "vessel.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace vessel_traffic {

/// Concrete CRTP repository implementation for Vessel.
/// Satisfies RepositoryBase<VesselRepositoryImpl<C>, Vessel> contract.
/// Uses parameterised SQL (pqxx) — no stored procedures (ADR 20260120).
template<typename Connection>
class VesselRepositoryImpl {
public:
    explicit VesselRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto build_select_by_id_query() const -> std::string {
        return "SELECT id, id, imo_number, mmsi, call_sign, name, vessel_type, flag_state, is_active FROM vessel_traffic.vessel WHERE id = $1";
    }

    [[nodiscard]] auto build_insert_query() const -> std::string {
        return "INSERT INTO vessel_traffic.vessel (id, id, imo_number, mmsi, call_sign, name, vessel_type, flag_state, is_active) VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9) RETURNING id";
    }

    [[nodiscard]] auto build_update_query() const -> std::string {
        return "UPDATE vessel_traffic.vessel SET id = $2, imo_number = $3, mmsi = $4, call_sign = $5, name = $6, vessel_type = $7, flag_state = $8, is_active = $9 WHERE id = $1";
    }

    [[nodiscard]] auto build_delete_query() const -> std::string {
        return "DELETE FROM vessel_traffic.vessel WHERE id = $1";
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> Vessel {
        return Vessel{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .imo_number = row[2].as<std::string>(),
            .mmsi = row[3].as<std::string>(),
            .call_sign = row[4].as<std::string>(),
            .name = row[5].as<std::string>(),
            .vessel_type = row[6].as<std::string>(),
            .flag_state = row[7].as<std::string>(),
            .is_active = row[8].as<std::string>(),
        };
    }

    auto save(const Vessel& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_insert_query(), entity.id, entity.id, entity.imo_number, entity.mmsi, entity.call_sign, entity.name, entity.vessel_type, entity.flag_state, entity.is_active);
        tx.commit();
    }

    auto update(const Vessel& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_update_query(), entity.id, entity.id, entity.imo_number, entity.mmsi, entity.call_sign, entity.name, entity.vessel_type, entity.flag_state, entity.is_active);
        if (result.affected_rows() == 0) {
            throw std::runtime_error("Vessel not found: " + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_delete_query(), id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<Vessel> {
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
