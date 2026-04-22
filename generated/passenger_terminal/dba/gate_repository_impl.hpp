#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "gate.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace passenger_terminal {

/// Concrete CRTP repository implementation for Gate.
/// Satisfies RepositoryBase<GateRepositoryImpl<C>, Gate> contract.
/// Uses parameterised SQL (pqxx) — no stored procedures (ADR 20260120).
template<typename Connection>
class GateRepositoryImpl {
public:
    explicit GateRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto build_select_by_id_query() const -> std::string {
        return "SELECT id, id, code, name, capacity, status, voyage_id FROM passenger_terminal.gate WHERE id = $1";
    }

    [[nodiscard]] auto build_insert_query() const -> std::string {
        return "INSERT INTO passenger_terminal.gate (id, id, code, name, capacity, status, voyage_id) VALUES ($1, $2, $3, $4, $5, $6, $7) RETURNING id";
    }

    [[nodiscard]] auto build_update_query() const -> std::string {
        return "UPDATE passenger_terminal.gate SET id = $2, code = $3, name = $4, capacity = $5, status = $6, voyage_id = $7 WHERE id = $1";
    }

    [[nodiscard]] auto build_delete_query() const -> std::string {
        return "DELETE FROM passenger_terminal.gate WHERE id = $1";
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> Gate {
        return Gate{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .code = row[2].as<std::string>(),
            .name = row[3].as<std::string>(),
            .capacity = row[4].as<std::string>(),
            .status = row[5].as<std::string>(),
            .voyage_id = row[6].as<std::string>(),
        };
    }

    auto save(const Gate& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_insert_query(), entity.id, entity.id, entity.code, entity.name, entity.capacity, entity.status, entity.voyage_id);
        tx.commit();
    }

    auto update(const Gate& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_update_query(), entity.id, entity.id, entity.code, entity.name, entity.capacity, entity.status, entity.voyage_id);
        if (result.affected_rows() == 0) {
            throw std::runtime_error("Gate not found: " + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_delete_query(), id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<Gate> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_select_by_id_query(), id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

private:
    Connection& conn_;
};

} // namespace passenger_terminal
