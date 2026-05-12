#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "vessel.hpp"
#include "vessel_traffic_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace vessel_traffic {

/// Concrete CRTP repository implementation for Vessel.
/// Satisfies RepositoryBase<VesselRepositoryImpl<C>, Vessel> contract.
/// Uses embedded SQL constants from vessel_traffic_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class VesselRepositoryImpl {
public:
    explicit VesselRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const Vessel& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::VesselInsert, entity.id, entity.id, entity.imo_number, entity.mmsi, entity.call_sign, entity.name, entity.vessel_type, entity.flag_state, entity.is_active);
        tx.commit();
    }

    auto update(const Vessel& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::VesselUpdate, entity.id, entity.id, entity.imo_number, entity.mmsi, entity.call_sign, entity.name, entity.vessel_type, entity.flag_state, entity.is_active);
        if (result.affected_rows() == 0) {
            throw std::runtime_error(Vessel not found:  + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::VesselDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<Vessel> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::VesselSelectById, id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<Vessel> {
        auto tx = conn_.begin();
        auto result = tx.exec(queries::VesselSelectAll);
        tx.commit();
        auto out = std::vector<Vessel>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> Vessel {
        return Vessel{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .imo_number = row[2].as<std::string>(),
            .mmsi = row[3].as<std::string>(),
            .call_sign = row[4].as<std::string>(),
            .name = row[5].as<std::string>(),
            .vessel_type = row[6].as<std::string>(),
            .flag_state = row[7].as<std::string>(),
            .is_active = row[8].as<std::string>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace vessel_traffic
