#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "truck_visit.hpp"
#include "intermodal_transfer_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace intermodal_transfer {

/// Concrete CRTP repository implementation for TruckVisit.
/// Satisfies RepositoryBase<TruckVisitRepositoryImpl<C>, TruckVisit> contract.
/// Uses embedded SQL constants from intermodal_transfer_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class TruckVisitRepositoryImpl {
public:
    explicit TruckVisitRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const TruckVisit& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::TruckVisitInsert, entity.id, entity.id, entity.truck_plate, entity.carrier_name, entity.slot_id, entity.arrived_at, entity.departed_at);
        tx.commit();
    }

    auto update(const TruckVisit& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::TruckVisitUpdate, entity.id, entity.id, entity.truck_plate, entity.carrier_name, entity.slot_id, entity.arrived_at, entity.departed_at);
        if (result.affected_rows() == 0) {
            throw std::runtime_error(TruckVisit not found:  + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::TruckVisitDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<TruckVisit> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::TruckVisitSelectById, id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<TruckVisit> {
        auto tx = conn_.begin();
        auto result = tx.exec(queries::TruckVisitSelectAll);
        tx.commit();
        auto out = std::vector<TruckVisit>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> TruckVisit {
        return TruckVisit{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .truck_plate = row[2].as<std::string>(),
            .carrier_name = row[3].as<std::string>(),
            .slot_id = row[4].as<std::string>(),
            .arrived_at = row[5].as<std::string>(),
            .departed_at = row[6].as<std::string>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace intermodal_transfer
