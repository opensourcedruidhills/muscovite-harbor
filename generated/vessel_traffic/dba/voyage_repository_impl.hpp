#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "voyage.hpp"
#include "vessel_traffic_queries.hpp"
#include <algorithm>
#include <iterator>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>

namespace vessel_traffic {

class DbaOperationSpan {
public:
    explicit DbaOperationSpan(std::string_view operation) : operation_{operation} {}
    auto set_status_ok() noexcept -> void {}
    auto set_error(std::string_view /*message*/) noexcept -> void {}
private:
    std::string_view operation_;
};

/// Concrete CRTP repository implementation for Voyage.
/// Satisfies RepositoryBase<VoyageRepositoryImpl<C>, Voyage> contract.
/// Uses embedded SQL constants from vessel_traffic_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class VoyageRepositoryImpl {
public:
    explicit VoyageRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const Voyage& entity) -> void {
        DbaOperationSpan span("VoyageRepositoryImpl::save");
        auto tx = conn_.begin();
        tx.exec_params(queries::VoyageInsert, entity.id, entity.vessel_id, entity.berth_id, entity.voyage_number, entity.eta, entity.ata, entity.etd, entity.atd, entity.cargo_category, entity.status);
        tx.commit();
        span.set_status_ok();
    }

    auto update(const Voyage& entity) -> void {
        DbaOperationSpan span("VoyageRepositoryImpl::update");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::VoyageUpdate, entity.id, entity.vessel_id, entity.berth_id, entity.voyage_number, entity.eta, entity.ata, entity.etd, entity.atd, entity.cargo_category, entity.status);
        if (result.affected_rows() == 0) {
            span.set_error("not found");
            throw std::runtime_error("Voyage not found: " + entity.id);
        }
        tx.commit();
        span.set_status_ok();
    }

    auto remove(const std::string& id) -> void {
        DbaOperationSpan span("VoyageRepositoryImpl::remove");
        auto tx = conn_.begin();
        tx.exec_params(queries::VoyageDelete, id);
        tx.commit();
        span.set_status_ok();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<Voyage> {
        DbaOperationSpan span("VoyageRepositoryImpl::find_by_id");
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

    [[nodiscard]] auto find_all() -> std::vector<Voyage> {
        DbaOperationSpan span("VoyageRepositoryImpl::find_all");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::VoyageSelectAll);
        tx.commit();
        auto out = std::vector<Voyage>{ };
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        span.set_status_ok();
        return out;
    }

    /// Filter all entities by a domain specification (in-memory).
    template<typename Spec>
    [[nodiscard]] auto filter_by_spec(const Spec& spec) const -> std::vector<Voyage> {
        auto all = find_all();
        auto result = std::vector<Voyage>{};
        std::copy_if(all.begin(), all.end(), std::back_inserter(result),
                     [&spec](const Voyage& e) { return spec.is_satisfied_by(e); });
        return result;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> Voyage {
        return Voyage{
            .id = row[0].as<std::string>(),
            .vessel_id = row[1].as<boost::uuids::uuid>(),
            .berth_id = row[2].as<boost::uuids::uuid>(),
            .voyage_number = row[3].as<std::string>(),
            .eta = row[4].as<muscovite::dba::Timestamp>(),
            .ata = row[5].as<muscovite::dba::Timestamp>(),
            .etd = row[6].as<muscovite::dba::Timestamp>(),
            .atd = row[7].as<muscovite::dba::Timestamp>(),
            .cargo_category = row[8].as<std::string>(),
            .status = row[9].as<std::string>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace vessel_traffic
