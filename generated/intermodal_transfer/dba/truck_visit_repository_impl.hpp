#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "truck_visit.hpp"
#include "intermodal_transfer_queries.hpp"
#include <algorithm>
#include <iterator>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>

namespace intermodal_transfer {

class DbaOperationSpan {
public:
    explicit DbaOperationSpan(std::string_view operation) : operation_{operation} {}
    auto set_status_ok() noexcept -> void {}
    auto set_error(std::string_view /*message*/) noexcept -> void {}
private:
    std::string_view operation_;
};

/// Concrete CRTP repository implementation for TruckVisit.
/// Satisfies RepositoryBase<TruckVisitRepositoryImpl<C>, TruckVisit> contract.
/// Uses embedded SQL constants from intermodal_transfer_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class TruckVisitRepositoryImpl {
public:
    explicit TruckVisitRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const TruckVisit& entity) -> void {
        DbaOperationSpan span("TruckVisitRepositoryImpl::save");
        auto tx = conn_.begin();
        tx.exec_params(queries::TruckVisitInsert, entity.id, entity.truck_plate, entity.carrier_name, entity.slot_id, entity.arrived_at, entity.departed_at);
        tx.commit();
        span.set_status_ok();
    }

    auto update(const TruckVisit& entity) -> void {
        DbaOperationSpan span("TruckVisitRepositoryImpl::update");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::TruckVisitUpdate, entity.id, entity.truck_plate, entity.carrier_name, entity.slot_id, entity.arrived_at, entity.departed_at);
        if (result.affected_rows() == 0) {
            span.set_error("not found");
            throw std::runtime_error("TruckVisit not found: " + entity.id);
        }
        tx.commit();
        span.set_status_ok();
    }

    auto remove(const std::string& id) -> void {
        DbaOperationSpan span("TruckVisitRepositoryImpl::remove");
        auto tx = conn_.begin();
        tx.exec_params(queries::TruckVisitDelete, id);
        tx.commit();
        span.set_status_ok();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<TruckVisit> {
        DbaOperationSpan span("TruckVisitRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::TruckVisitSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        auto mapped = map_row(result[0]);
        span.set_status_ok();
        return mapped;
    }

    [[nodiscard]] auto find_all() -> std::vector<TruckVisit> {
        DbaOperationSpan span("TruckVisitRepositoryImpl::find_all");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::TruckVisitSelectAll);
        tx.commit();
        auto out = std::vector<TruckVisit>{ };
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        span.set_status_ok();
        return out;
    }

    /// Filter all entities by a domain specification (in-memory).
    template<typename Spec>
    [[nodiscard]] auto filter_by_spec(const Spec& spec) const -> std::vector<TruckVisit> {
        auto all = find_all();
        auto result = std::vector<TruckVisit>{};
        std::copy_if(all.begin(), all.end(), std::back_inserter(result),
                     [&spec](const TruckVisit& e) { return spec.is_satisfied_by(e); });
        return result;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> TruckVisit {
        return TruckVisit{
            .id = row[0].as<std::string>(),
            .truck_plate = row[1].as<std::string>(),
            .carrier_name = row[2].as<std::string>(),
            .slot_id = row[3].as<boost::uuids::uuid>(),
            .arrived_at = row[4].as<muscovite::dba::Timestamp>(),
            .departed_at = row[5].as<muscovite::dba::Timestamp>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace intermodal_transfer
