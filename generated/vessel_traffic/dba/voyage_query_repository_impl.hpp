#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "voyage_query_repository.hpp"
#include "vessel_traffic_queries.hpp"
#include <cstdint>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

namespace vessel_traffic {

class DbaOperationSpan {
public:
    explicit DbaOperationSpan(std::string_view operation) : operation_{operation} {}
    auto set_status_ok() noexcept -> void {}
    auto set_error(std::string_view /*message*/) noexcept -> void {}
private:
    std::string_view operation_;
};

/// pqxx-based query repository implementation for Voyage aggregate.
/// Uses embedded SQL constants from vessel_traffic_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class VoyageQueryRepositoryImpl : public VoyageQueryRepository {
public:
    explicit VoyageQueryRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto find_by_id(const Voyage::Id& id) -> std::optional<Voyage> override {
        DbaOperationSpan span("VoyageQueryRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::VoyageSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        auto mapped = map_row(result[0]);
        span.set_status_ok();
        return mapped;
    }

    [[nodiscard]] auto find_all() -> std::vector<Voyage> override {
        DbaOperationSpan span("VoyageQueryRepositoryImpl::find_all");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::VoyageSelectAll);
        tx.commit();
        auto out = std::vector<Voyage>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        span.set_status_ok();
        return out;
    }

    [[nodiscard]] auto count() -> std::int64_t override {
        DbaOperationSpan span("VoyageQueryRepositoryImpl::count");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::VoyageCount);
        tx.commit();
        auto total = result[0][0].as<std::int64_t>();
        span.set_status_ok();
        return total;
    }

    [[nodiscard]] auto find_by_vessels_by_eta(const muscovite::dba::Timestamp& from_eta, const muscovite::dba::Timestamp& to_eta) -> std::vector<Voyage> override {
        DbaOperationSpan span("VoyageQueryRepositoryImpl::find_by_vessels_by_eta");
        auto tx = conn_.begin();
        auto result = tx.exec_params("SELECT id, id, vessel_id, berth_id, voyage_number, eta, ata, etd, atd, cargo_category, status FROM vessel_traffic.voyage WHERE eta BETWEEN from_eta AND to_eta AND status != 'DEPARTED'", from_eta, to_eta);
        tx.commit();
        auto out = std::vector<Voyage>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        span.set_status_ok();
        return out;
    }

private:
    Connection& conn_;

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> Voyage {
        return Voyage{
            .id = row[0].as<std::string>(),
            .id = row[1].as<boost::uuids::uuid>(),
            .vessel_id = row[2].as<boost::uuids::uuid>(),
            .berth_id = row[3].as<boost::uuids::uuid>(),
            .voyage_number = row[4].as<std::string>(),
            .eta = row[5].as<muscovite::dba::Timestamp>(),
            .ata = row[6].as<muscovite::dba::Timestamp>(),
            .etd = row[7].as<muscovite::dba::Timestamp>(),
            .atd = row[8].as<muscovite::dba::Timestamp>(),
            .cargo_category = row[9].as<std::string>(),
            .status = row[10].as<std::string>(),
        };
    }
;

} // namespace vessel_traffic
