#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "crane.hpp"
#include "cargo_operations_queries.hpp"
#include <algorithm>
#include <iterator>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>

namespace cargo_operations {

class DbaOperationSpan {
public:
    explicit DbaOperationSpan(std::string_view operation) : operation_{operation} {}
    auto set_status_ok() noexcept -> void {}
    auto set_error(std::string_view /*message*/) noexcept -> void {}
private:
    std::string_view operation_;
};

/// Concrete CRTP repository implementation for Crane.
/// Satisfies RepositoryBase<CraneRepositoryImpl<C>, Crane> contract.
/// Uses embedded SQL constants from cargo_operations_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class CraneRepositoryImpl {
public:
    explicit CraneRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const Crane& entity) -> void {
        DbaOperationSpan span("CraneRepositoryImpl::save");
        auto tx = conn_.begin();
        tx.exec_params(queries::CraneInsert, entity.id, entity.name, entity.crane_type, entity.max_lift_kg, entity.is_active);
        tx.commit();
        span.set_status_ok();
    }

    auto update(const Crane& entity) -> void {
        DbaOperationSpan span("CraneRepositoryImpl::update");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::CraneUpdate, entity.id, entity.name, entity.crane_type, entity.max_lift_kg, entity.is_active);
        if (result.affected_rows() == 0) {
            span.set_error("not found");
            throw std::runtime_error("Crane not found: " + entity.id);
        }
        tx.commit();
        span.set_status_ok();
    }

    auto remove(const std::string& id) -> void {
        DbaOperationSpan span("CraneRepositoryImpl::remove");
        auto tx = conn_.begin();
        tx.exec_params(queries::CraneDelete, id);
        tx.commit();
        span.set_status_ok();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<Crane> {
        DbaOperationSpan span("CraneRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::CraneSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        auto mapped = map_row(result[0]);
        span.set_status_ok();
        return mapped;
    }

    [[nodiscard]] auto find_all() -> std::vector<Crane> {
        DbaOperationSpan span("CraneRepositoryImpl::find_all");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::CraneSelectAll);
        tx.commit();
        auto out = std::vector<Crane>{ };
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        span.set_status_ok();
        return out;
    }

    /// Filter all entities by a domain specification (in-memory).
    template<typename Spec>
    [[nodiscard]] auto filter_by_spec(const Spec& spec) const -> std::vector<Crane> {
        auto all = find_all();
        auto result = std::vector<Crane>{};
        std::copy_if(all.begin(), all.end(), std::back_inserter(result),
                     [&spec](const Crane& e) { return spec.is_satisfied_by(e); });
        return result;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> Crane {
        return Crane{
            .id = row[0].as<std::string>(),
            .name = row[1].as<std::string>(),
            .crane_type = row[2].as<std::string>(),
            .max_lift_kg = row[3].as<muscovite::dba::Decimal>(),
            .is_active = row[4].as<bool>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace cargo_operations
