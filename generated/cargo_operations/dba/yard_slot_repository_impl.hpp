#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "yard_slot.hpp"
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

/// Concrete CRTP repository implementation for YardSlot.
/// Satisfies RepositoryBase<YardSlotRepositoryImpl<C>, YardSlot> contract.
/// Uses embedded SQL constants from cargo_operations_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class YardSlotRepositoryImpl {
public:
    explicit YardSlotRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const YardSlot& entity) -> void {
        DbaOperationSpan span("YardSlotRepositoryImpl::save");
        auto tx = conn_.begin();
        tx.exec_params(queries::YardSlotInsert, entity.id, entity.code, entity.max_weight_kg, entity.max_tier, entity.has_power, entity.is_occupied);
        tx.commit();
        span.set_status_ok();
    }

    auto update(const YardSlot& entity) -> void {
        DbaOperationSpan span("YardSlotRepositoryImpl::update");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::YardSlotUpdate, entity.id, entity.code, entity.max_weight_kg, entity.max_tier, entity.has_power, entity.is_occupied);
        if (result.affected_rows() == 0) {
            span.set_error("not found");
            throw std::runtime_error("YardSlot not found: " + entity.id);
        }
        tx.commit();
        span.set_status_ok();
    }

    auto remove(const std::string& id) -> void {
        DbaOperationSpan span("YardSlotRepositoryImpl::remove");
        auto tx = conn_.begin();
        tx.exec_params(queries::YardSlotDelete, id);
        tx.commit();
        span.set_status_ok();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<YardSlot> {
        DbaOperationSpan span("YardSlotRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::YardSlotSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        auto mapped = map_row(result[0]);
        span.set_status_ok();
        return mapped;
    }

    [[nodiscard]] auto find_all() -> std::vector<YardSlot> {
        DbaOperationSpan span("YardSlotRepositoryImpl::find_all");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::YardSlotSelectAll);
        tx.commit();
        auto out = std::vector<YardSlot>{ };
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        span.set_status_ok();
        return out;
    }

    /// Filter all entities by a domain specification (in-memory).
    template<typename Spec>
    [[nodiscard]] auto filter_by_spec(const Spec& spec) const -> std::vector<YardSlot> {
        auto all = find_all();
        auto result = std::vector<YardSlot>{};
        std::copy_if(all.begin(), all.end(), std::back_inserter(result),
                     [&spec](const YardSlot& e) { return spec.is_satisfied_by(e); });
        return result;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> YardSlot {
        return YardSlot{
            .id = row[0].as<std::string>(),
            .code = row[1].as<std::string>(),
            .max_weight_kg = row[2].as<muscovite::dba::Decimal>(),
            .max_tier = row[3].as<std::int32_t>(),
            .has_power = row[4].as<bool>(),
            .is_occupied = row[5].as<bool>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace cargo_operations
