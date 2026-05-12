#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "chassis_unit.hpp"
#include "intermodal_transfer_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace intermodal_transfer {

/// Concrete CRTP repository implementation for ChassisUnit.
/// Satisfies RepositoryBase<ChassisUnitRepositoryImpl<C>, ChassisUnit> contract.
/// Uses embedded SQL constants from intermodal_transfer_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class ChassisUnitRepositoryImpl {
public:
    explicit ChassisUnitRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const ChassisUnit& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::ChassisUnitInsert, entity.id, entity.id, entity.chassis_number, entity.chassis_type, entity.is_available);
        tx.commit();
    }

    auto update(const ChassisUnit& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::ChassisUnitUpdate, entity.id, entity.id, entity.chassis_number, entity.chassis_type, entity.is_available);
        if (result.affected_rows() == 0) {
            throw std::runtime_error(ChassisUnit not found:  + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::ChassisUnitDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<ChassisUnit> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::ChassisUnitSelectById, id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<ChassisUnit> {
        auto tx = conn_.begin();
        auto result = tx.exec(queries::ChassisUnitSelectAll);
        tx.commit();
        auto out = std::vector<ChassisUnit>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> ChassisUnit {
        return ChassisUnit{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .chassis_number = row[2].as<std::string>(),
            .chassis_type = row[3].as<std::string>(),
            .is_available = row[4].as<std::string>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace intermodal_transfer
