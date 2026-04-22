#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "parcel_command_repository.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace cargo_decomposition {

/// pqxx-based command repository implementation for Parcel aggregate.
/// Uses direct parameterised SQL — no stored procedures (ADR 20260120).
template<typename Connection>
class ParcelCommandRepositoryImpl : public ParcelCommandRepository {
public:
    explicit ParcelCommandRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const Parcel& entity) -> void override {
        auto tx = conn_.begin();
        tx.exec_params("INSERT INTO cargo_decomposition.parcel (id, id, tracking_number, pallet_id, weight_kg, hs_code, description) VALUES ($1, $2, $3, $4, $5, $6, $7) ON CONFLICT (id) DO UPDATE SET id = $2, tracking_number = $3, pallet_id = $4, weight_kg = $5, hs_code = $6, description = $7",
            entity.id, entity.id, entity.tracking_number, entity.pallet_id, entity.weight_kg, entity.hs_code, entity.description);
        tx.commit();
    }

    auto remove(const Parcel::Id& id) -> void override {
        auto tx = conn_.begin();
        tx.exec_params("DELETE FROM cargo_decomposition.parcel WHERE id = $1", id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const Parcel::Id& id) -> std::optional<Parcel> override {
        auto tx = conn_.begin();
        auto result = tx.exec_params("SELECT id, id, tracking_number, pallet_id, weight_kg, hs_code, description FROM cargo_decomposition.parcel WHERE id = $1", id);
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
};

} // namespace cargo_decomposition
