#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "reefer_unit.hpp"
#include "cargo_operations_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace cargo_operations {

/// Concrete CRTP repository implementation for ReeferUnit.
/// Satisfies RepositoryBase<ReeferUnitRepositoryImpl<C>, ReeferUnit> contract.
/// Uses embedded SQL constants from cargo_operations_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class ReeferUnitRepositoryImpl {
public:
    explicit ReeferUnitRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const ReeferUnit& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::ReeferUnitInsert, entity.id, entity.id, entity.container_id, entity.target_temp_c, entity.current_temp_c, entity.is_powered);
        tx.commit();
    }

    auto update(const ReeferUnit& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::ReeferUnitUpdate, entity.id, entity.id, entity.container_id, entity.target_temp_c, entity.current_temp_c, entity.is_powered);
        if (result.affected_rows() == 0) {
            throw std::runtime_error(ReeferUnit not found:  + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::ReeferUnitDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<ReeferUnit> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::ReeferUnitSelectById, id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<ReeferUnit> {
        auto tx = conn_.begin();
        auto result = tx.exec(queries::ReeferUnitSelectAll);
        tx.commit();
        auto out = std::vector<ReeferUnit>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> ReeferUnit {
        return ReeferUnit{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .container_id = row[2].as<std::string>(),
            .target_temp_c = row[3].as<std::string>(),
            .current_temp_c = row[4].as<std::string>(),
            .is_powered = row[5].as<std::string>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace cargo_operations
