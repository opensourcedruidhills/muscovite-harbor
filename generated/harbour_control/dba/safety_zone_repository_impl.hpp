#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "safety_zone.hpp"
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

/// Concrete CRTP repository implementation for SafetyZone.
/// Satisfies RepositoryBase<SafetyZoneRepositoryImpl<C>, SafetyZone> contract.
/// Uses embedded SQL constants from harbour_control_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class SafetyZoneRepositoryImpl {
public:
    explicit SafetyZoneRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const SafetyZone& entity) -> void {
        DbaOperationSpan span("SafetyZoneRepositoryImpl::save");
        auto tx = conn_.begin();
        tx.exec_params(queries::SafetyZoneInsert, entity.id, entity.zone_code, entity.zone_name, entity.security_level, entity.max_hazmat_class, entity.is_restricted);
        tx.commit();
        span.set_status_ok();
    }

    auto update(const SafetyZone& entity) -> void {
        DbaOperationSpan span("SafetyZoneRepositoryImpl::update");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::SafetyZoneUpdate, entity.id, entity.zone_code, entity.zone_name, entity.security_level, entity.max_hazmat_class, entity.is_restricted);
        if (result.affected_rows() == 0) {
            span.set_error("not found");
            throw std::runtime_error("SafetyZone not found: " + entity.id);
        }
        tx.commit();
        span.set_status_ok();
    }

    auto remove(const std::string& id) -> void {
        DbaOperationSpan span("SafetyZoneRepositoryImpl::remove");
        auto tx = conn_.begin();
        tx.exec_params(queries::SafetyZoneDelete, id);
        tx.commit();
        span.set_status_ok();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<SafetyZone> {
        DbaOperationSpan span("SafetyZoneRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::SafetyZoneSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        auto mapped = map_row(result[0]);
        span.set_status_ok();
        return mapped;
    }

    [[nodiscard]] auto find_all() -> std::vector<SafetyZone> {
        DbaOperationSpan span("SafetyZoneRepositoryImpl::find_all");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::SafetyZoneSelectAll);
        tx.commit();
        auto out = std::vector<SafetyZone>{ };
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        span.set_status_ok();
        return out;
    }

    /// Filter all entities by a domain specification (in-memory).
    template<typename Spec>
    [[nodiscard]] auto filter_by_spec(const Spec& spec) const -> std::vector<SafetyZone> {
        auto all = find_all();
        auto result = std::vector<SafetyZone>{};
        std::copy_if(all.begin(), all.end(), std::back_inserter(result),
                     [&spec](const SafetyZone& e) { return spec.is_satisfied_by(e); });
        return result;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> SafetyZone {
        return SafetyZone{
            .id = row[0].as<std::string>(),
            .zone_code = row[1].as<std::string>(),
            .zone_name = row[2].as<std::string>(),
            .security_level = row[3].as<std::string>(),
            .max_hazmat_class = row[4].as<std::int32_t>(),
            .is_restricted = row[5].as<bool>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace harbour_control
