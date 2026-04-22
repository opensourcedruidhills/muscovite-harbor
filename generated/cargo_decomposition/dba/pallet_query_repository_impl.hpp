#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "pallet_query_repository.hpp"
#include <cstdint>
#include <optional>
#include <stdexcept>
#include <string>
#include <vector>

namespace cargo_decomposition {

/// pqxx-based query repository implementation for Pallet aggregate.
/// Uses direct parameterised SQL — no stored procedures (ADR 20260120).
template<typename Connection>
class PalletQueryRepositoryImpl : public PalletQueryRepository {
public:
    explicit PalletQueryRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto find_by_id(const Pallet::Id& id) -> std::optional<Pallet> override {
        auto tx = conn_.begin();
        auto result = tx.exec_params("SELECT id, id, pallet_id, container_id, weight_kg, length_cm, width_cm, height_cm, hs_code FROM cargo_decomposition.pallet WHERE id = $1", id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<Pallet> override {
        auto tx = conn_.begin();
        auto result = tx.exec("SELECT id, id, pallet_id, container_id, weight_kg, length_cm, width_cm, height_cm, hs_code FROM cargo_decomposition.pallet ORDER BY id");
        tx.commit();
        auto out = std::vector<Pallet>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
    }

    [[nodiscard]] auto count() -> std::int64_t override {
        auto tx = conn_.begin();
        auto result = tx.exec("SELECT COUNT(*) FROM cargo_decomposition.pallet");
        tx.commit();
        return result[0][0].as<std::int64_t>();
    }

private:
    Connection& conn_;

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
};

} // namespace cargo_decomposition
