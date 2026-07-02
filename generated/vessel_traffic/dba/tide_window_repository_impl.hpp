#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "tide_window.hpp"
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

/// Concrete CRTP repository implementation for TideWindow.
/// Satisfies RepositoryBase<TideWindowRepositoryImpl<C>, TideWindow> contract.
/// Uses embedded SQL constants from vessel_traffic_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class TideWindowRepositoryImpl {
public:
    explicit TideWindowRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const TideWindow& entity) -> void {
        DbaOperationSpan span("TideWindowRepositoryImpl::save");
        auto tx = conn_.begin();
        tx.exec_params(queries::TideWindowInsert, entity.id, entity.berth_id, entity.tide_height_metres, entity.available_draft);
        tx.commit();
        span.set_status_ok();
    }

    auto update(const TideWindow& entity) -> void {
        DbaOperationSpan span("TideWindowRepositoryImpl::update");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::TideWindowUpdate, entity.id, entity.berth_id, entity.tide_height_metres, entity.available_draft);
        if (result.affected_rows() == 0) {
            span.set_error("not found");
            throw std::runtime_error("TideWindow not found: " + entity.id);
        }
        tx.commit();
        span.set_status_ok();
    }

    auto remove(const std::string& id) -> void {
        DbaOperationSpan span("TideWindowRepositoryImpl::remove");
        auto tx = conn_.begin();
        tx.exec_params(queries::TideWindowDelete, id);
        tx.commit();
        span.set_status_ok();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<TideWindow> {
        DbaOperationSpan span("TideWindowRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::TideWindowSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        auto mapped = map_row(result[0]);
        span.set_status_ok();
        return mapped;
    }

    [[nodiscard]] auto find_all() -> std::vector<TideWindow> {
        DbaOperationSpan span("TideWindowRepositoryImpl::find_all");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::TideWindowSelectAll);
        tx.commit();
        auto out = std::vector<TideWindow>{ };
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        span.set_status_ok();
        return out;
    }

    /// Filter all entities by a domain specification (in-memory).
    template<typename Spec>
    [[nodiscard]] auto filter_by_spec(const Spec& spec) const -> std::vector<TideWindow> {
        auto all = find_all();
        auto result = std::vector<TideWindow>{};
        std::copy_if(all.begin(), all.end(), std::back_inserter(result),
                     [&spec](const TideWindow& e) { return spec.is_satisfied_by(e); });
        return result;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> TideWindow {
        return TideWindow{
            .id = row[0].as<std::string>(),
            .berth_id = row[1].as<boost::uuids::uuid>(),
            .tide_height_metres = row[2].as<muscovite::dba::Decimal>(),
            .available_draft = row[3].as<muscovite::dba::Decimal>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace vessel_traffic
