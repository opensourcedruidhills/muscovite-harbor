#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "gate.hpp"
#include "passenger_terminal_queries.hpp"
#include <algorithm>
#include <iterator>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>

namespace passenger_terminal {

class DbaOperationSpan {
public:
    explicit DbaOperationSpan(std::string_view operation) : operation_{operation} {}
    auto set_status_ok() noexcept -> void {}
    auto set_error(std::string_view /*message*/) noexcept -> void {}
private:
    std::string_view operation_;
};

/// Concrete CRTP repository implementation for Gate.
/// Satisfies RepositoryBase<GateRepositoryImpl<C>, Gate> contract.
/// Uses embedded SQL constants from passenger_terminal_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class GateRepositoryImpl {
public:
    explicit GateRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const Gate& entity) -> void {
        DbaOperationSpan span("GateRepositoryImpl::save");
        auto tx = conn_.begin();
        tx.exec_params(queries::GateInsert, entity.id, entity.code, entity.name, entity.capacity, entity.status, entity.voyage_id);
        tx.commit();
        span.set_status_ok();
    }

    auto update(const Gate& entity) -> void {
        DbaOperationSpan span("GateRepositoryImpl::update");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::GateUpdate, entity.id, entity.code, entity.name, entity.capacity, entity.status, entity.voyage_id);
        if (result.affected_rows() == 0) {
            span.set_error("not found");
            throw std::runtime_error("Gate not found: " + entity.id);
        }
        tx.commit();
        span.set_status_ok();
    }

    auto remove(const std::string& id) -> void {
        DbaOperationSpan span("GateRepositoryImpl::remove");
        auto tx = conn_.begin();
        tx.exec_params(queries::GateDelete, id);
        tx.commit();
        span.set_status_ok();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<Gate> {
        DbaOperationSpan span("GateRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::GateSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        auto mapped = map_row(result[0]);
        span.set_status_ok();
        return mapped;
    }

    [[nodiscard]] auto find_all() -> std::vector<Gate> {
        DbaOperationSpan span("GateRepositoryImpl::find_all");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::GateSelectAll);
        tx.commit();
        auto out = std::vector<Gate>{ };
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        span.set_status_ok();
        return out;
    }

    /// Filter all entities by a domain specification (in-memory).
    template<typename Spec>
    [[nodiscard]] auto filter_by_spec(const Spec& spec) const -> std::vector<Gate> {
        auto all = find_all();
        auto result = std::vector<Gate>{};
        std::copy_if(all.begin(), all.end(), std::back_inserter(result),
                     [&spec](const Gate& e) { return spec.is_satisfied_by(e); });
        return result;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> Gate {
        return Gate{
            .id = row[0].as<std::string>(),
            .code = row[1].as<std::string>(),
            .name = row[2].as<std::string>(),
            .capacity = row[3].as<std::int32_t>(),
            .status = row[4].as<std::string>(),
            .voyage_id = row[5].as<boost::uuids::uuid>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace passenger_terminal
