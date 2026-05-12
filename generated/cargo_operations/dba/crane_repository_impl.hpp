#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "crane.hpp"
#include "cargo_operations_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace cargo_operations {

/// Concrete CRTP repository implementation for Crane.
/// Satisfies RepositoryBase<CraneRepositoryImpl<C>, Crane> contract.
/// Uses embedded SQL constants from cargo_operations_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class CraneRepositoryImpl {
public:
    explicit CraneRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const Crane& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::CraneInsert, entity.id, entity.id, entity.name, entity.crane_type, entity.max_lift_kg, entity.is_active);
        tx.commit();
    }

    auto update(const Crane& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::CraneUpdate, entity.id, entity.id, entity.name, entity.crane_type, entity.max_lift_kg, entity.is_active);
        if (result.affected_rows() == 0) {
            throw std::runtime_error(Crane not found:  + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::CraneDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<Crane> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::CraneSelectById, id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<Crane> {
        auto tx = conn_.begin();
        auto result = tx.exec(queries::CraneSelectAll);
        tx.commit();
        auto out = std::vector<Crane>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> Crane {
        return Crane{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .name = row[2].as<std::string>(),
            .crane_type = row[3].as<std::string>(),
            .max_lift_kg = row[4].as<std::string>(),
            .is_active = row[5].as<std::string>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace cargo_operations
