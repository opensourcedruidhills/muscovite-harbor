#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "rail_wagon.hpp"
#include "intermodal_transfer_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace intermodal_transfer {

/// Concrete CRTP repository implementation for RailWagon.
/// Satisfies RepositoryBase<RailWagonRepositoryImpl<C>, RailWagon> contract.
/// Uses embedded SQL constants from intermodal_transfer_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class RailWagonRepositoryImpl {
public:
    explicit RailWagonRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const RailWagon& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::RailWagonInsert, entity.id, entity.id, entity.wagon_number, entity.max_weight_kg, entity.slot_id);
        tx.commit();
    }

    auto update(const RailWagon& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::RailWagonUpdate, entity.id, entity.id, entity.wagon_number, entity.max_weight_kg, entity.slot_id);
        if (result.affected_rows() == 0) {
            throw std::runtime_error(RailWagon not found:  + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::RailWagonDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<RailWagon> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::RailWagonSelectById, id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<RailWagon> {
        auto tx = conn_.begin();
        auto result = tx.exec(queries::RailWagonSelectAll);
        tx.commit();
        auto out = std::vector<RailWagon>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
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

private:
    Connection& conn_;
;

} // namespace intermodal_transfer
