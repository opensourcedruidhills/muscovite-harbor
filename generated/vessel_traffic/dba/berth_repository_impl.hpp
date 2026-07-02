#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "berth.hpp"
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

/// Concrete CRTP repository implementation for Berth.
/// Satisfies RepositoryBase<BerthRepositoryImpl<C>, Berth> contract.
/// Uses embedded SQL constants from vessel_traffic_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class BerthRepositoryImpl {
public:
    explicit BerthRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const Berth& entity) -> void {
        DbaOperationSpan span("BerthRepositoryImpl::save");
        auto tx = conn_.begin();
        tx.exec_params(queries::BerthInsert, entity.id, entity.code, entity.name, entity.max_loa_metres, entity.max_draft_metres, entity.max_beam_metres, entity.has_crane_access, entity.has_reefer_plugs, entity.is_active);
        tx.commit();
        span.set_status_ok();
    }

    auto update(const Berth& entity) -> void {
        DbaOperationSpan span("BerthRepositoryImpl::update");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::BerthUpdate, entity.id, entity.code, entity.name, entity.max_loa_metres, entity.max_draft_metres, entity.max_beam_metres, entity.has_crane_access, entity.has_reefer_plugs, entity.is_active);
        if (result.affected_rows() == 0) {
            span.set_error("not found");
            throw std::runtime_error("Berth not found: " + entity.id);
        }
        tx.commit();
        span.set_status_ok();
    }

    auto remove(const std::string& id) -> void {
        DbaOperationSpan span("BerthRepositoryImpl::remove");
        auto tx = conn_.begin();
        tx.exec_params(queries::BerthDelete, id);
        tx.commit();
        span.set_status_ok();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<Berth> {
        DbaOperationSpan span("BerthRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::BerthSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        auto mapped = map_row(result[0]);
        span.set_status_ok();
        return mapped;
    }

    [[nodiscard]] auto find_all() -> std::vector<Berth> {
        DbaOperationSpan span("BerthRepositoryImpl::find_all");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::BerthSelectAll);
        tx.commit();
        auto out = std::vector<Berth>{ };
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        span.set_status_ok();
        return out;
    }

    /// Filter all entities by a domain specification (in-memory).
    template<typename Spec>
    [[nodiscard]] auto filter_by_spec(const Spec& spec) const -> std::vector<Berth> {
        auto all = find_all();
        auto result = std::vector<Berth>{};
        std::copy_if(all.begin(), all.end(), std::back_inserter(result),
                     [&spec](const Berth& e) { return spec.is_satisfied_by(e); });
        return result;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> Berth {
        return Berth{
            .id = row[0].as<std::string>(),
            .code = row[1].as<std::string>(),
            .name = row[2].as<std::string>(),
            .max_loa_metres = row[3].as<muscovite::dba::Decimal>(),
            .max_draft_metres = row[4].as<muscovite::dba::Decimal>(),
            .max_beam_metres = row[5].as<muscovite::dba::Decimal>(),
            .has_crane_access = row[6].as<bool>(),
            .has_reefer_plugs = row[7].as<bool>(),
            .is_active = row[8].as<bool>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace vessel_traffic
