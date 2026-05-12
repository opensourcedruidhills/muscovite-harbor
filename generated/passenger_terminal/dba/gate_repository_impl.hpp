#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "gate.hpp"
#include "passenger_terminal_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace passenger_terminal {

/// Concrete CRTP repository implementation for Gate.
/// Satisfies RepositoryBase<GateRepositoryImpl<C>, Gate> contract.
/// Uses embedded SQL constants from passenger_terminal_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class GateRepositoryImpl {
public:
    explicit GateRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const Gate& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::GateInsert, entity.id, entity.id, entity.code, entity.name, entity.capacity, entity.status, entity.voyage_id);
        tx.commit();
    }

    auto update(const Gate& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::GateUpdate, entity.id, entity.id, entity.code, entity.name, entity.capacity, entity.status, entity.voyage_id);
        if (result.affected_rows() == 0) {
            throw std::runtime_error(Gate not found:  + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::GateDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<Gate> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::GateSelectById, id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<Gate> {
        auto tx = conn_.begin();
        auto result = tx.exec(queries::GateSelectAll);
        tx.commit();
        auto out = std::vector<Gate>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
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

private:
    Connection& conn_;
;

} // namespace passenger_terminal
