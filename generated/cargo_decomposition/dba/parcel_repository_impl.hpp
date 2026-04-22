#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "parcel.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace cargo_decomposition {

/// Concrete CRTP repository implementation for Parcel.
/// Satisfies RepositoryBase<ParcelRepositoryImpl<C>, Parcel> contract.
/// Uses parameterised SQL (pqxx) — no stored procedures (ADR 20260120).
template<typename Connection>
class ParcelRepositoryImpl {
public:
    explicit ParcelRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto build_select_by_id_query() const -> std::string {
        return "SELECT id, id, tracking_number, pallet_id, weight_kg, hs_code, description FROM cargo_decomposition.parcel WHERE id = $1";
    }

    [[nodiscard]] auto build_insert_query() const -> std::string {
        return "INSERT INTO cargo_decomposition.parcel (id, id, tracking_number, pallet_id, weight_kg, hs_code, description) VALUES ($1, $2, $3, $4, $5, $6, $7) RETURNING id";
    }

    [[nodiscard]] auto build_update_query() const -> std::string {
        return "UPDATE cargo_decomposition.parcel SET id = $2, tracking_number = $3, pallet_id = $4, weight_kg = $5, hs_code = $6, description = $7 WHERE id = $1";
    }

    [[nodiscard]] auto build_delete_query() const -> std::string {
        return "DELETE FROM cargo_decomposition.parcel WHERE id = $1";
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> Parcel {
        return Parcel{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .tracking_number = row[2].as<std::string>(),
            .pallet_id = row[3].as<std::string>(),
            .weight_kg = row[4].as<std::string>(),
            .hs_code = row[5].as<std::string>(),
            .description = row[6].as<std::string>(),
        };
    }

    auto save(const Parcel& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_insert_query(), entity.id, entity.id, entity.tracking_number, entity.pallet_id, entity.weight_kg, entity.hs_code, entity.description);
        tx.commit();
    }

    auto update(const Parcel& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_update_query(), entity.id, entity.id, entity.tracking_number, entity.pallet_id, entity.weight_kg, entity.hs_code, entity.description);
        if (result.affected_rows() == 0) {
            throw std::runtime_error("Parcel not found: " + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_delete_query(), id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<Parcel> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_select_by_id_query(), id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

private:
    Connection& conn_;
};

} // namespace cargo_decomposition
