#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "hazmat_permit.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace harbour_control {

/// Concrete CRTP repository implementation for HazmatPermit.
/// Satisfies RepositoryBase<HazmatPermitRepositoryImpl<C>, HazmatPermit> contract.
/// Uses parameterised SQL (pqxx) — no stored procedures (ADR 20260120).
template<typename Connection>
class HazmatPermitRepositoryImpl {
public:
    explicit HazmatPermitRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto build_select_by_id_query() const -> std::string {
        return "SELECT id, id, permit_number, vessel_id, imo_class, quantity_kg, approved, valid_from, valid_until FROM harbour_control.hazmat_permit WHERE id = $1";
    }

    [[nodiscard]] auto build_insert_query() const -> std::string {
        return "INSERT INTO harbour_control.hazmat_permit (id, id, permit_number, vessel_id, imo_class, quantity_kg, approved, valid_from, valid_until) VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9) RETURNING id";
    }

    [[nodiscard]] auto build_update_query() const -> std::string {
        return "UPDATE harbour_control.hazmat_permit SET id = $2, permit_number = $3, vessel_id = $4, imo_class = $5, quantity_kg = $6, approved = $7, valid_from = $8, valid_until = $9 WHERE id = $1";
    }

    [[nodiscard]] auto build_delete_query() const -> std::string {
        return "DELETE FROM harbour_control.hazmat_permit WHERE id = $1";
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> HazmatPermit {
        return HazmatPermit{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .permit_number = row[2].as<std::string>(),
            .vessel_id = row[3].as<std::string>(),
            .imo_class = row[4].as<std::string>(),
            .quantity_kg = row[5].as<std::string>(),
            .approved = row[6].as<std::string>(),
            .valid_from = row[7].as<std::string>(),
            .valid_until = row[8].as<std::string>(),
        };
    }

    auto save(const HazmatPermit& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_insert_query(), entity.id, entity.id, entity.permit_number, entity.vessel_id, entity.imo_class, entity.quantity_kg, entity.approved, entity.valid_from, entity.valid_until);
        tx.commit();
    }

    auto update(const HazmatPermit& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_update_query(), entity.id, entity.id, entity.permit_number, entity.vessel_id, entity.imo_class, entity.quantity_kg, entity.approved, entity.valid_from, entity.valid_until);
        if (result.affected_rows() == 0) {
            throw std::runtime_error("HazmatPermit not found: " + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_delete_query(), id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<HazmatPermit> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_select_by_id_query(), id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

private:
    Connection& conn_;
};

} // namespace harbour_control
