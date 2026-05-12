#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "yard_slot.hpp"
#include "cargo_operations_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace cargo_operations {

/// Concrete CRTP repository implementation for YardSlot.
/// Satisfies RepositoryBase<YardSlotRepositoryImpl<C>, YardSlot> contract.
/// Uses embedded SQL constants from cargo_operations_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class YardSlotRepositoryImpl {
public:
    explicit YardSlotRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const YardSlot& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::YardSlotInsert, entity.id, entity.id, entity.code, entity.max_weight_kg, entity.max_tier, entity.has_power, entity.is_occupied);
        tx.commit();
    }

    auto update(const YardSlot& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::YardSlotUpdate, entity.id, entity.id, entity.code, entity.max_weight_kg, entity.max_tier, entity.has_power, entity.is_occupied);
        if (result.affected_rows() == 0) {
            throw std::runtime_error(YardSlot not found:  + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::YardSlotDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<YardSlot> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::YardSlotSelectById, id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<YardSlot> {
        auto tx = conn_.begin();
        auto result = tx.exec(queries::YardSlotSelectAll);
        tx.commit();
        auto out = std::vector<YardSlot>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> YardSlot {
        return YardSlot{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .code = row[2].as<std::string>(),
            .max_weight_kg = row[3].as<std::string>(),
            .max_tier = row[4].as<std::string>(),
            .has_power = row[5].as<std::string>(),
            .is_occupied = row[6].as<std::string>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace cargo_operations
