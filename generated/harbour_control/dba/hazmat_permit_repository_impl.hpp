#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "hazmat_permit.hpp"
#include "harbour_control_queries.hpp"
#include <algorithm>
#include <iterator>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>

namespace harbour_control {

class DbaOperationSpan {
public:
    explicit DbaOperationSpan(std::string_view operation) : operation_{operation} {}
    auto set_status_ok() noexcept -> void {}
    auto set_error(std::string_view /*message*/) noexcept -> void {}
private:
    std::string_view operation_;
};

/// Concrete CRTP repository implementation for HazmatPermit.
/// Satisfies RepositoryBase<HazmatPermitRepositoryImpl<C>, HazmatPermit> contract.
/// Uses embedded SQL constants from harbour_control_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class HazmatPermitRepositoryImpl {
public:
    explicit HazmatPermitRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const HazmatPermit& entity) -> void {
        DbaOperationSpan span("HazmatPermitRepositoryImpl::save");
        auto tx = conn_.begin();
        tx.exec_params(queries::HazmatPermitInsert, entity.id, entity.permit_number, entity.vessel_id, entity.imo_class, entity.quantity_kg, entity.approved, entity.valid_from, entity.valid_until);
        tx.commit();
        span.set_status_ok();
    }

    auto update(const HazmatPermit& entity) -> void {
        DbaOperationSpan span("HazmatPermitRepositoryImpl::update");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::HazmatPermitUpdate, entity.id, entity.permit_number, entity.vessel_id, entity.imo_class, entity.quantity_kg, entity.approved, entity.valid_from, entity.valid_until);
        if (result.affected_rows() == 0) {
            span.set_error("not found");
            throw std::runtime_error("HazmatPermit not found: " + entity.id);
        }
        tx.commit();
        span.set_status_ok();
    }

    auto remove(const std::string& id) -> void {
        DbaOperationSpan span("HazmatPermitRepositoryImpl::remove");
        auto tx = conn_.begin();
        tx.exec_params(queries::HazmatPermitDelete, id);
        tx.commit();
        span.set_status_ok();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<HazmatPermit> {
        DbaOperationSpan span("HazmatPermitRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::HazmatPermitSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        auto mapped = map_row(result[0]);
        span.set_status_ok();
        return mapped;
    }

    [[nodiscard]] auto find_all() -> std::vector<HazmatPermit> {
        DbaOperationSpan span("HazmatPermitRepositoryImpl::find_all");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::HazmatPermitSelectAll);
        tx.commit();
        auto out = std::vector<HazmatPermit>{ };
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        span.set_status_ok();
        return out;
    }

    /// Filter all entities by a domain specification (in-memory).
    template<typename Spec>
    [[nodiscard]] auto filter_by_spec(const Spec& spec) const -> std::vector<HazmatPermit> {
        auto all = find_all();
        auto result = std::vector<HazmatPermit>{};
        std::copy_if(all.begin(), all.end(), std::back_inserter(result),
                     [&spec](const HazmatPermit& e) { return spec.is_satisfied_by(e); });
        return result;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> HazmatPermit {
        return HazmatPermit{
            .id = row[0].as<std::string>(),
            .permit_number = row[1].as<std::string>(),
            .vessel_id = row[2].as<boost::uuids::uuid>(),
            .imo_class = row[3].as<std::int32_t>(),
            .quantity_kg = row[4].as<muscovite::dba::Decimal>(),
            .approved = row[5].as<bool>(),
            .valid_from = row[6].as<muscovite::dba::Timestamp>(),
            .valid_until = row[7].as<muscovite::dba::Timestamp>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace harbour_control
