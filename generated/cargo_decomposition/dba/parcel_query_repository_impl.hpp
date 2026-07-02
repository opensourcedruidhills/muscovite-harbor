#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "parcel_query_repository.hpp"
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

/// pqxx-based query repository implementation for Parcel aggregate.
/// Uses embedded SQL constants from cargo_decomposition_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class ParcelQueryRepositoryImpl : public ParcelQueryRepository {
public:
    explicit ParcelQueryRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto find_by_id(const Parcel::Id& id) -> std::optional<Parcel> override {
        DbaOperationSpan span("ParcelQueryRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::ParcelSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        auto mapped = map_row(result[0]);
        span.set_status_ok();
        return mapped;
    }

    [[nodiscard]] auto find_all() -> std::vector<Parcel> override {
        DbaOperationSpan span("ParcelQueryRepositoryImpl::find_all");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::ParcelSelectAll);
        tx.commit();
        auto out = std::vector<Parcel>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        span.set_status_ok();
        return out;
    }

    [[nodiscard]] auto count() -> std::int64_t override {
        DbaOperationSpan span("ParcelQueryRepositoryImpl::count");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::ParcelCount);
        tx.commit();
        auto total = result[0][0].as<std::int64_t>();
        span.set_status_ok();
        return total;
    }

private:
    Connection& conn_;

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> Parcel {
        return Parcel{
            .id = row[0].as<std::string>(),
            .id = row[1].as<boost::uuids::uuid>(),
            .tracking_number = row[2].as<std::string>(),
            .pallet_id = row[3].as<boost::uuids::uuid>(),
            .weight_kg = row[4].as<muscovite::dba::Decimal>(),
            .hs_code = row[5].as<std::string>(),
            .description = row[6].as<std::string>(),
        };
    }
;

} // namespace cargo_decomposition
