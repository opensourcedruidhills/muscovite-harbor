#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "break_bulk_item.hpp"
#include "cargo_decomposition_queries.hpp"
#include <algorithm>
#include <iterator>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>

namespace cargo_decomposition {

class DbaOperationSpan {
public:
    explicit DbaOperationSpan(std::string_view operation) : operation_{operation} {}
    auto set_status_ok() noexcept -> void {}
    auto set_error(std::string_view /*message*/) noexcept -> void {}
private:
    std::string_view operation_;
};

/// Concrete CRTP repository implementation for BreakBulkItem.
/// Satisfies RepositoryBase<BreakBulkItemRepositoryImpl<C>, BreakBulkItem> contract.
/// Uses embedded SQL constants from cargo_decomposition_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class BreakBulkItemRepositoryImpl {
public:
    explicit BreakBulkItemRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const BreakBulkItem& entity) -> void {
        DbaOperationSpan span("BreakBulkItemRepositoryImpl::save");
        auto tx = conn_.begin();
        tx.exec_params(queries::BreakBulkItemInsert, entity.id, entity.container_id, entity.item_type, entity.weight_kg, entity.requires_crane);
        tx.commit();
        span.set_status_ok();
    }

    auto update(const BreakBulkItem& entity) -> void {
        DbaOperationSpan span("BreakBulkItemRepositoryImpl::update");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::BreakBulkItemUpdate, entity.id, entity.container_id, entity.item_type, entity.weight_kg, entity.requires_crane);
        if (result.affected_rows() == 0) {
            span.set_error("not found");
            throw std::runtime_error("BreakBulkItem not found: " + entity.id);
        }
        tx.commit();
        span.set_status_ok();
    }

    auto remove(const std::string& id) -> void {
        DbaOperationSpan span("BreakBulkItemRepositoryImpl::remove");
        auto tx = conn_.begin();
        tx.exec_params(queries::BreakBulkItemDelete, id);
        tx.commit();
        span.set_status_ok();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<BreakBulkItem> {
        DbaOperationSpan span("BreakBulkItemRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::BreakBulkItemSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        auto mapped = map_row(result[0]);
        span.set_status_ok();
        return mapped;
    }

    [[nodiscard]] auto find_all() -> std::vector<BreakBulkItem> {
        DbaOperationSpan span("BreakBulkItemRepositoryImpl::find_all");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::BreakBulkItemSelectAll);
        tx.commit();
        auto out = std::vector<BreakBulkItem>{ };
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        span.set_status_ok();
        return out;
    }

    /// Filter all entities by a domain specification (in-memory).
    template<typename Spec>
    [[nodiscard]] auto filter_by_spec(const Spec& spec) const -> std::vector<BreakBulkItem> {
        auto all = find_all();
        auto result = std::vector<BreakBulkItem>{};
        std::copy_if(all.begin(), all.end(), std::back_inserter(result),
                     [&spec](const BreakBulkItem& e) { return spec.is_satisfied_by(e); });
        return result;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> BreakBulkItem {
        return BreakBulkItem{
            .id = row[0].as<std::string>(),
            .container_id = row[1].as<boost::uuids::uuid>(),
            .item_type = row[2].as<std::string>(),
            .weight_kg = row[3].as<muscovite::dba::Decimal>(),
            .requires_crane = row[4].as<bool>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace cargo_decomposition
