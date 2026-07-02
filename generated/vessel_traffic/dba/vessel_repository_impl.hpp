#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "vessel.hpp"
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

/// Concrete CRTP repository implementation for Vessel.
/// Satisfies RepositoryBase<VesselRepositoryImpl<C>, Vessel> contract.
/// Uses embedded SQL constants from vessel_traffic_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class VesselRepositoryImpl {
public:
    explicit VesselRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const Vessel& entity) -> void {
        DbaOperationSpan span("VesselRepositoryImpl::save");
        auto tx = conn_.begin();
        tx.exec_params(queries::VesselInsert, entity.id, entity.imo_number, entity.mmsi, entity.call_sign, entity.name, entity.vessel_type, entity.flag_state, entity.is_active);
        tx.commit();
        span.set_status_ok();
    }

    auto update(const Vessel& entity) -> void {
        DbaOperationSpan span("VesselRepositoryImpl::update");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::VesselUpdate, entity.id, entity.imo_number, entity.mmsi, entity.call_sign, entity.name, entity.vessel_type, entity.flag_state, entity.is_active);
        if (result.affected_rows() == 0) {
            span.set_error("not found");
            throw std::runtime_error("Vessel not found: " + entity.id);
        }
        tx.commit();
        span.set_status_ok();
    }

    auto remove(const std::string& id) -> void {
        DbaOperationSpan span("VesselRepositoryImpl::remove");
        auto tx = conn_.begin();
        tx.exec_params(queries::VesselDelete, id);
        tx.commit();
        span.set_status_ok();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<Vessel> {
        DbaOperationSpan span("VesselRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::VesselSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        auto mapped = map_row(result[0]);
        span.set_status_ok();
        return mapped;
    }

    [[nodiscard]] auto find_all() -> std::vector<Vessel> {
        DbaOperationSpan span("VesselRepositoryImpl::find_all");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::VesselSelectAll);
        tx.commit();
        auto out = std::vector<Vessel>{ };
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        span.set_status_ok();
        return out;
    }

    /// Filter all entities by a domain specification (in-memory).
    template<typename Spec>
    [[nodiscard]] auto filter_by_spec(const Spec& spec) const -> std::vector<Vessel> {
        auto all = find_all();
        auto result = std::vector<Vessel>{};
        std::copy_if(all.begin(), all.end(), std::back_inserter(result),
                     [&spec](const Vessel& e) { return spec.is_satisfied_by(e); });
        return result;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> Vessel {
        return Vessel{
            .id = row[0].as<std::string>(),
            .imo_number = row[1].as<std::string>(),
            .mmsi = row[2].as<std::string>(),
            .call_sign = row[3].as<std::string>(),
            .name = row[4].as<std::string>(),
            .vessel_type = row[5].as<std::string>(),
            .flag_state = row[6].as<std::string>(),
            .is_active = row[7].as<bool>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace vessel_traffic
