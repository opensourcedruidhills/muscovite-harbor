#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "rail_wagon.hpp"
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

/// Concrete CRTP repository implementation for RailWagon.
/// Satisfies RepositoryBase<RailWagonRepositoryImpl<C>, RailWagon> contract.
/// Uses embedded SQL constants from intermodal_transfer_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class RailWagonRepositoryImpl {
public:
    explicit RailWagonRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const RailWagon& entity) -> void {
        DbaOperationSpan span("RailWagonRepositoryImpl::save");
        auto tx = conn_.begin();
        tx.exec_params(queries::RailWagonInsert, entity.id, entity.wagon_number, entity.max_weight_kg, entity.slot_id);
        tx.commit();
        span.set_status_ok();
    }

    auto update(const RailWagon& entity) -> void {
        DbaOperationSpan span("RailWagonRepositoryImpl::update");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::RailWagonUpdate, entity.id, entity.wagon_number, entity.max_weight_kg, entity.slot_id);
        if (result.affected_rows() == 0) {
            span.set_error("not found");
            throw std::runtime_error("RailWagon not found: " + entity.id);
        }
        tx.commit();
        span.set_status_ok();
    }

    auto remove(const std::string& id) -> void {
        DbaOperationSpan span("RailWagonRepositoryImpl::remove");
        auto tx = conn_.begin();
        tx.exec_params(queries::RailWagonDelete, id);
        tx.commit();
        span.set_status_ok();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<RailWagon> {
        DbaOperationSpan span("RailWagonRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::RailWagonSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        auto mapped = map_row(result[0]);
        span.set_status_ok();
        return mapped;
    }

    [[nodiscard]] auto find_all() -> std::vector<RailWagon> {
        DbaOperationSpan span("RailWagonRepositoryImpl::find_all");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::RailWagonSelectAll);
        tx.commit();
        auto out = std::vector<RailWagon>{ };
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        span.set_status_ok();
        return out;
    }

    /// Filter all entities by a domain specification (in-memory).
    template<typename Spec>
    [[nodiscard]] auto filter_by_spec(const Spec& spec) const -> std::vector<RailWagon> {
        auto all = find_all();
        auto result = std::vector<RailWagon>{};
        std::copy_if(all.begin(), all.end(), std::back_inserter(result),
                     [&spec](const RailWagon& e) { return spec.is_satisfied_by(e); });
        return result;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> RailWagon {
        return RailWagon{
            .id = row[0].as<std::string>(),
            .wagon_number = row[1].as<std::string>(),
            .max_weight_kg = row[2].as<muscovite::dba::Decimal>(),
            .slot_id = row[3].as<boost::uuids::uuid>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace intermodal_transfer
