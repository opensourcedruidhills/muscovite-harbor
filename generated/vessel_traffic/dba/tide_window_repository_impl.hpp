#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "tide_window.hpp"
#include "vessel_traffic_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace vessel_traffic {

/// Concrete CRTP repository implementation for TideWindow.
/// Satisfies RepositoryBase<TideWindowRepositoryImpl<C>, TideWindow> contract.
/// Uses embedded SQL constants from vessel_traffic_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class TideWindowRepositoryImpl {
public:
    explicit TideWindowRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const TideWindow& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::TideWindowInsert, entity.id, entity.id, entity.berth_id, entity.tide_height_metres, entity.available_draft);
        tx.commit();
    }

    auto update(const TideWindow& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::TideWindowUpdate, entity.id, entity.id, entity.berth_id, entity.tide_height_metres, entity.available_draft);
        if (result.affected_rows() == 0) {
            throw std::runtime_error(TideWindow not found:  + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::TideWindowDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<TideWindow> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::TideWindowSelectById, id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<TideWindow> {
        auto tx = conn_.begin();
        auto result = tx.exec(queries::TideWindowSelectAll);
        tx.commit();
        auto out = std::vector<TideWindow>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> TideWindow {
        return TideWindow{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .berth_id = row[2].as<std::string>(),
            .tide_height_metres = row[3].as<std::string>(),
            .available_draft = row[4].as<std::string>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace vessel_traffic
