#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "parcel_command_repository.hpp"
#include "cargo_decomposition_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace cargo_decomposition {

/// pqxx-based command repository implementation for Parcel aggregate.
/// Uses embedded SQL constants from cargo_decomposition_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class ParcelCommandRepositoryImpl : public ParcelCommandRepository {
public:
    explicit ParcelCommandRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const Parcel& entity) -> void override {
        auto tx = conn_.begin();
        tx.exec_params(queries::ParcelUpsert,
            entity.id, entity.id, entity.tracking_number, entity.pallet_id, entity.weight_kg, entity.hs_code, entity.description);
        tx.commit();
    }

    auto remove(const Parcel::Id& id) -> void override {
        auto tx = conn_.begin();
        tx.exec_params(queries::ParcelDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const Parcel::Id& id) -> std::optional<Parcel> override {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::ParcelSelectById, id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        const auto& row = result[0];
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

private:
    Connection& conn_;
;

} // namespace cargo_decomposition
