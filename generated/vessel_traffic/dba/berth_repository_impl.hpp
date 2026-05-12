#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "berth.hpp"
#include "vessel_traffic_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace vessel_traffic {

/// Concrete CRTP repository implementation for Berth.
/// Satisfies RepositoryBase<BerthRepositoryImpl<C>, Berth> contract.
/// Uses embedded SQL constants from vessel_traffic_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class BerthRepositoryImpl {
public:
    explicit BerthRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const Berth& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::BerthInsert, entity.id, entity.id, entity.code, entity.name, entity.max_loa_metres, entity.max_draft_metres, entity.max_beam_metres, entity.has_crane_access, entity.has_reefer_plugs, entity.is_active);
        tx.commit();
    }

    auto update(const Berth& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::BerthUpdate, entity.id, entity.id, entity.code, entity.name, entity.max_loa_metres, entity.max_draft_metres, entity.max_beam_metres, entity.has_crane_access, entity.has_reefer_plugs, entity.is_active);
        if (result.affected_rows() == 0) {
            throw std::runtime_error(Berth not found:  + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::BerthDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<Berth> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::BerthSelectById, id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<Berth> {
        auto tx = conn_.begin();
        auto result = tx.exec(queries::BerthSelectAll);
        tx.commit();
        auto out = std::vector<Berth>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
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

private:
    Connection& conn_;
;

} // namespace vessel_traffic
