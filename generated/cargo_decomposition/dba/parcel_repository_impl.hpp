#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "parcel.hpp"
#include "cargo_decomposition_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace cargo_decomposition {

/// Concrete CRTP repository implementation for Parcel.
/// Satisfies RepositoryBase<ParcelRepositoryImpl<C>, Parcel> contract.
/// Uses embedded SQL constants from cargo_decomposition_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class ParcelRepositoryImpl {
public:
    explicit ParcelRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const Parcel& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::ParcelInsert, entity.id, entity.id, entity.tracking_number, entity.pallet_id, entity.weight_kg, entity.hs_code, entity.description);
        tx.commit();
    }

    auto update(const Parcel& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::ParcelUpdate, entity.id, entity.id, entity.tracking_number, entity.pallet_id, entity.weight_kg, entity.hs_code, entity.description);
        if (result.affected_rows() == 0) {
            throw std::runtime_error(Parcel not found:  + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::ParcelDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<Parcel> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::ParcelSelectById, id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<Parcel> {
        auto tx = conn_.begin();
        auto result = tx.exec(queries::ParcelSelectAll);
        tx.commit();
        auto out = std::vector<Parcel>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
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

private:
    Connection& conn_;
;

} // namespace cargo_decomposition
