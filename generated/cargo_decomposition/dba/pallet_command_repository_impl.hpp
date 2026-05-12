#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "pallet_command_repository.hpp"
#include "cargo_decomposition_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace cargo_decomposition {

/// pqxx-based command repository implementation for Pallet aggregate.
/// Uses embedded SQL constants from cargo_decomposition_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class PalletCommandRepositoryImpl : public PalletCommandRepository {
public:
    explicit PalletCommandRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const Pallet& entity) -> void override {
        auto tx = conn_.begin();
        tx.exec_params(queries::PalletUpsert,
            entity.id, entity.id, entity.pallet_id, entity.container_id, entity.weight_kg, entity.length_cm, entity.width_cm, entity.height_cm, entity.hs_code);
        tx.commit();
    }

    auto remove(const Pallet::Id& id) -> void override {
        auto tx = conn_.begin();
        tx.exec_params(queries::PalletDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const Pallet::Id& id) -> std::optional<Pallet> override {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::PalletSelectById, id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        const auto& row = result[0];
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
