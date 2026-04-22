#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "berth.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace vessel_traffic {

/// Concrete CRTP repository implementation for Berth.
/// Satisfies RepositoryBase<BerthRepositoryImpl<C>, Berth> contract.
/// Uses parameterised SQL (pqxx) — no stored procedures (ADR 20260120).
template<typename Connection>
class BerthRepositoryImpl {
public:
    explicit BerthRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto build_select_by_id_query() const -> std::string {
        return "SELECT id, id, code, name, max_loa_metres, max_draft_metres, max_beam_metres, has_crane_access, has_reefer_plugs, is_active FROM vessel_traffic.berth WHERE id = $1";
    }

    [[nodiscard]] auto build_insert_query() const -> std::string {
        return "INSERT INTO vessel_traffic.berth (id, id, code, name, max_loa_metres, max_draft_metres, max_beam_metres, has_crane_access, has_reefer_plugs, is_active) VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10) RETURNING id";
    }

    [[nodiscard]] auto build_update_query() const -> std::string {
        return "UPDATE vessel_traffic.berth SET id = $2, code = $3, name = $4, max_loa_metres = $5, max_draft_metres = $6, max_beam_metres = $7, has_crane_access = $8, has_reefer_plugs = $9, is_active = $10 WHERE id = $1";
    }

    [[nodiscard]] auto build_delete_query() const -> std::string {
        return "DELETE FROM vessel_traffic.berth WHERE id = $1";
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> Berth {
        return Berth{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .code = row[2].as<std::string>(),
            .name = row[3].as<std::string>(),
            .max_loa_metres = row[4].as<std::string>(),
            .max_draft_metres = row[5].as<std::string>(),
            .max_beam_metres = row[6].as<std::string>(),
            .has_crane_access = row[7].as<std::string>(),
            .has_reefer_plugs = row[8].as<std::string>(),
            .is_active = row[9].as<std::string>(),
        };
    }

    auto save(const Berth& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_insert_query(), entity.id, entity.id, entity.code, entity.name, entity.max_loa_metres, entity.max_draft_metres, entity.max_beam_metres, entity.has_crane_access, entity.has_reefer_plugs, entity.is_active);
        tx.commit();
    }

    auto update(const Berth& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_update_query(), entity.id, entity.id, entity.code, entity.name, entity.max_loa_metres, entity.max_draft_metres, entity.max_beam_metres, entity.has_crane_access, entity.has_reefer_plugs, entity.is_active);
        if (result.affected_rows() == 0) {
            throw std::runtime_error("Berth not found: " + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_delete_query(), id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<Berth> {
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
