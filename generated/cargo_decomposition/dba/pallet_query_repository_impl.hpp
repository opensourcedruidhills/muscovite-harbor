#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "pallet_query_repository.hpp"
#include "cargo_decomposition_queries.hpp"
#include <cstdint>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

namespace cargo_decomposition {

class DbaOperationSpan {
public:
    explicit DbaOperationSpan(std::string_view operation) : operation_{operation} {}
    auto set_status_ok() noexcept -> void {}
    auto set_error(std::string_view /*message*/) noexcept -> void {}
private:
    std::string_view operation_;
};

/// pqxx-based query repository implementation for Pallet aggregate.
/// Uses embedded SQL constants from cargo_decomposition_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class PalletQueryRepositoryImpl : public PalletQueryRepository {
public:
    explicit PalletQueryRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto find_by_id(const Pallet::Id& id) -> std::optional<Pallet> override {
        DbaOperationSpan span("PalletQueryRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::PalletSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        auto mapped = map_row(result[0]);
        span.set_status_ok();
        return mapped;
    }

    [[nodiscard]] auto find_all() -> std::vector<Pallet> override {
        DbaOperationSpan span("PalletQueryRepositoryImpl::find_all");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::PalletSelectAll);
        tx.commit();
        auto out = std::vector<Pallet>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        span.set_status_ok();
        return out;
    }

    [[nodiscard]] auto count() -> std::int64_t override {
        DbaOperationSpan span("PalletQueryRepositoryImpl::count");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::PalletCount);
        tx.commit();
        auto total = result[0][0].as<std::int64_t>();
        span.set_status_ok();
        return total;
    }

private:
    Connection& conn_;

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> Pallet {
        return Pallet{
            .id = row[0].as<std::string>(),
            .id = row[1].as<boost::uuids::uuid>(),
            .pallet_id = row[2].as<std::string>(),
            .container_id = row[3].as<boost::uuids::uuid>(),
            .weight_kg = row[4].as<muscovite::dba::Decimal>(),
            .length_cm = row[5].as<muscovite::dba::Decimal>(),
            .width_cm = row[6].as<muscovite::dba::Decimal>(),
            .height_cm = row[7].as<muscovite::dba::Decimal>(),
            .hs_code = row[8].as<std::string>(),
        };
    }
;

} // namespace cargo_decomposition
