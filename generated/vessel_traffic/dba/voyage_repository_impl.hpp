#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "voyage.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace vessel_traffic {

/// Concrete CRTP repository implementation for Voyage.
/// Satisfies RepositoryBase<VoyageRepositoryImpl<C>, Voyage> contract.
/// Uses parameterised SQL (pqxx) — no stored procedures (ADR 20260120).
template<typename Connection>
class VoyageRepositoryImpl {
public:
    explicit VoyageRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto build_select_by_id_query() const -> std::string {
        return "SELECT id, id, vessel_id, berth_id, voyage_number, eta, ata, etd, atd, cargo_category, status FROM vessel_traffic.voyage WHERE id = $1";
    }

    [[nodiscard]] auto build_insert_query() const -> std::string {
        return "INSERT INTO vessel_traffic.voyage (id, id, vessel_id, berth_id, voyage_number, eta, ata, etd, atd, cargo_category, status) VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11) RETURNING id";
    }

    [[nodiscard]] auto build_update_query() const -> std::string {
        return "UPDATE vessel_traffic.voyage SET id = $2, vessel_id = $3, berth_id = $4, voyage_number = $5, eta = $6, ata = $7, etd = $8, atd = $9, cargo_category = $10, status = $11 WHERE id = $1";
    }

    [[nodiscard]] auto build_delete_query() const -> std::string {
        return "DELETE FROM vessel_traffic.voyage WHERE id = $1";
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

    auto save(const Voyage& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_insert_query(), entity.id, entity.id, entity.vessel_id, entity.berth_id, entity.voyage_number, entity.eta, entity.ata, entity.etd, entity.atd, entity.cargo_category, entity.status);
        tx.commit();
    }

    auto update(const Voyage& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_update_query(), entity.id, entity.id, entity.vessel_id, entity.berth_id, entity.voyage_number, entity.eta, entity.ata, entity.etd, entity.atd, entity.cargo_category, entity.status);
        if (result.affected_rows() == 0) {
            throw std::runtime_error("Voyage not found: " + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_delete_query(), id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<Voyage> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_select_by_id_query(), id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

private:
    Connection& conn_;
};

} // namespace vessel_traffic
