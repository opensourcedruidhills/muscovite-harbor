#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "pallet.hpp"
#include "cargo_decomposition_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace cargo_decomposition {

/// Concrete CRTP repository implementation for Pallet.
/// Satisfies RepositoryBase<PalletRepositoryImpl<C>, Pallet> contract.
/// Uses embedded SQL constants from cargo_decomposition_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class PalletRepositoryImpl {
public:
    explicit PalletRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const Pallet& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::PalletInsert, entity.id, entity.id, entity.pallet_id, entity.container_id, entity.weight_kg, entity.length_cm, entity.width_cm, entity.height_cm, entity.hs_code);
        tx.commit();
    }

    auto update(const Pallet& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::PalletUpdate, entity.id, entity.id, entity.pallet_id, entity.container_id, entity.weight_kg, entity.length_cm, entity.width_cm, entity.height_cm, entity.hs_code);
        if (result.affected_rows() == 0) {
            throw std::runtime_error(Pallet not found:  + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::PalletDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<Pallet> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::PalletSelectById, id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<Pallet> {
        auto tx = conn_.begin();
        auto result = tx.exec(queries::PalletSelectAll);
        tx.commit();
        auto out = std::vector<Pallet>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
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

private:
    Connection& conn_;
;

} // namespace cargo_decomposition
