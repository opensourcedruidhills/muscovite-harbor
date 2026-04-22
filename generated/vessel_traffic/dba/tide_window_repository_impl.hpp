#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "tide_window.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace vessel_traffic {

/// Concrete CRTP repository implementation for TideWindow.
/// Satisfies RepositoryBase<TideWindowRepositoryImpl<C>, TideWindow> contract.
/// Uses parameterised SQL (pqxx) — no stored procedures (ADR 20260120).
template<typename Connection>
class TideWindowRepositoryImpl {
public:
    explicit TideWindowRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto build_select_by_id_query() const -> std::string {
        return "SELECT id, id, berth_id, tide_height_metres, available_draft FROM vessel_traffic.tide_window WHERE id = $1";
    }

    [[nodiscard]] auto build_insert_query() const -> std::string {
        return "INSERT INTO vessel_traffic.tide_window (id, id, berth_id, tide_height_metres, available_draft) VALUES ($1, $2, $3, $4, $5) RETURNING id";
    }

    [[nodiscard]] auto build_update_query() const -> std::string {
        return "UPDATE vessel_traffic.tide_window SET id = $2, berth_id = $3, tide_height_metres = $4, available_draft = $5 WHERE id = $1";
    }

    [[nodiscard]] auto build_delete_query() const -> std::string {
        return "DELETE FROM vessel_traffic.tide_window WHERE id = $1";
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

    auto save(const TideWindow& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_insert_query(), entity.id, entity.id, entity.berth_id, entity.tide_height_metres, entity.available_draft);
        tx.commit();
    }

    auto update(const TideWindow& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_update_query(), entity.id, entity.id, entity.berth_id, entity.tide_height_metres, entity.available_draft);
        if (result.affected_rows() == 0) {
            throw std::runtime_error("TideWindow not found: " + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_delete_query(), id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<TideWindow> {
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
