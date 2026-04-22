#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "pallet.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace cargo_decomposition {

/// Concrete CRTP repository implementation for Pallet.
/// Satisfies RepositoryBase<PalletRepositoryImpl<C>, Pallet> contract.
/// Uses parameterised SQL (pqxx) — no stored procedures (ADR 20260120).
template<typename Connection>
class PalletRepositoryImpl {
public:
    explicit PalletRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto build_select_by_id_query() const -> std::string {
        return "SELECT id, id, pallet_id, container_id, weight_kg, length_cm, width_cm, height_cm, hs_code FROM cargo_decomposition.pallet WHERE id = $1";
    }

    [[nodiscard]] auto build_insert_query() const -> std::string {
        return "INSERT INTO cargo_decomposition.pallet (id, id, pallet_id, container_id, weight_kg, length_cm, width_cm, height_cm, hs_code) VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9) RETURNING id";
    }

    [[nodiscard]] auto build_update_query() const -> std::string {
        return "UPDATE cargo_decomposition.pallet SET id = $2, pallet_id = $3, container_id = $4, weight_kg = $5, length_cm = $6, width_cm = $7, height_cm = $8, hs_code = $9 WHERE id = $1";
    }

    [[nodiscard]] auto build_delete_query() const -> std::string {
        return "DELETE FROM cargo_decomposition.pallet WHERE id = $1";
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> Pallet {
        return Pallet{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .pallet_id = row[2].as<std::string>(),
            .container_id = row[3].as<std::string>(),
            .weight_kg = row[4].as<std::string>(),
            .length_cm = row[5].as<std::string>(),
            .width_cm = row[6].as<std::string>(),
            .height_cm = row[7].as<std::string>(),
            .hs_code = row[8].as<std::string>(),
        };
    }

    auto save(const Pallet& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_insert_query(), entity.id, entity.id, entity.pallet_id, entity.container_id, entity.weight_kg, entity.length_cm, entity.width_cm, entity.height_cm, entity.hs_code);
        tx.commit();
    }

    auto update(const Pallet& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_update_query(), entity.id, entity.id, entity.pallet_id, entity.container_id, entity.weight_kg, entity.length_cm, entity.width_cm, entity.height_cm, entity.hs_code);
        if (result.affected_rows() == 0) {
            throw std::runtime_error("Pallet not found: " + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_delete_query(), id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<Pallet> {
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
