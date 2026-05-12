#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "voyage.hpp"
#include "vessel_traffic_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace vessel_traffic {

/// Concrete CRTP repository implementation for Voyage.
/// Satisfies RepositoryBase<VoyageRepositoryImpl<C>, Voyage> contract.
/// Uses embedded SQL constants from vessel_traffic_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class VoyageRepositoryImpl {
public:
    explicit VoyageRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const Voyage& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::VoyageInsert, entity.id, entity.id, entity.vessel_id, entity.berth_id, entity.voyage_number, entity.eta, entity.ata, entity.etd, entity.atd, entity.cargo_category, entity.status);
        tx.commit();
    }

    auto update(const Voyage& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::VoyageUpdate, entity.id, entity.id, entity.vessel_id, entity.berth_id, entity.voyage_number, entity.eta, entity.ata, entity.etd, entity.atd, entity.cargo_category, entity.status);
        if (result.affected_rows() == 0) {
            throw std::runtime_error(Voyage not found:  + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::VoyageDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<Voyage> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::VoyageSelectById, id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<Voyage> {
        auto tx = conn_.begin();
        auto result = tx.exec(queries::VoyageSelectAll);
        tx.commit();
        auto out = std::vector<Voyage>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> Voyage {
        return Voyage{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .vessel_id = row[2].as<std::string>(),
            .berth_id = row[3].as<std::string>(),
            .voyage_number = row[4].as<std::string>(),
            .eta = row[5].as<std::string>(),
            .ata = row[6].as<std::string>(),
            .etd = row[7].as<std::string>(),
            .atd = row[8].as<std::string>(),
            .cargo_category = row[9].as<std::string>(),
            .status = row[10].as<std::string>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace vessel_traffic
