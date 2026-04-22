#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "rail_wagon.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace intermodal_transfer {

/// Concrete CRTP repository implementation for RailWagon.
/// Satisfies RepositoryBase<RailWagonRepositoryImpl<C>, RailWagon> contract.
/// Uses parameterised SQL (pqxx) — no stored procedures (ADR 20260120).
template<typename Connection>
class RailWagonRepositoryImpl {
public:
    explicit RailWagonRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto build_select_by_id_query() const -> std::string {
        return "SELECT id, id, wagon_number, max_weight_kg, slot_id FROM intermodal_transfer.rail_wagon WHERE id = $1";
    }

    [[nodiscard]] auto build_insert_query() const -> std::string {
        return "INSERT INTO intermodal_transfer.rail_wagon (id, id, wagon_number, max_weight_kg, slot_id) VALUES ($1, $2, $3, $4, $5) RETURNING id";
    }

    [[nodiscard]] auto build_update_query() const -> std::string {
        return "UPDATE intermodal_transfer.rail_wagon SET id = $2, wagon_number = $3, max_weight_kg = $4, slot_id = $5 WHERE id = $1";
    }

    [[nodiscard]] auto build_delete_query() const -> std::string {
        return "DELETE FROM intermodal_transfer.rail_wagon WHERE id = $1";
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> RailWagon {
        return RailWagon{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .wagon_number = row[2].as<std::string>(),
            .max_weight_kg = row[3].as<std::string>(),
            .slot_id = row[4].as<std::string>(),
        };
    }

    auto save(const RailWagon& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_insert_query(), entity.id, entity.id, entity.wagon_number, entity.max_weight_kg, entity.slot_id);
        tx.commit();
    }

    auto update(const RailWagon& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_update_query(), entity.id, entity.id, entity.wagon_number, entity.max_weight_kg, entity.slot_id);
        if (result.affected_rows() == 0) {
            throw std::runtime_error("RailWagon not found: " + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_delete_query(), id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<RailWagon> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_select_by_id_query(), id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

private:
    Connection& conn_;
};

} // namespace intermodal_transfer
