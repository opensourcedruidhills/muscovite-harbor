#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "discharge_sequence.hpp"
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

/// Concrete CRTP repository implementation for DischargeSequence.
/// Satisfies RepositoryBase<DischargeSequenceRepositoryImpl<C>, DischargeSequence> contract.
/// Uses embedded SQL constants from cargo_operations_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class DischargeSequenceRepositoryImpl {
public:
    explicit DischargeSequenceRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const DischargeSequence& entity) -> void {
        DbaOperationSpan span("DischargeSequenceRepositoryImpl::save");
        auto tx = conn_.begin();
        tx.exec_params(queries::DischargeSequenceInsert, entity.id, entity.load_plan_id, entity.container_id, entity.sequence_order, entity.crane_id);
        tx.commit();
        span.set_status_ok();
    }

    auto update(const DischargeSequence& entity) -> void {
        DbaOperationSpan span("DischargeSequenceRepositoryImpl::update");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::DischargeSequenceUpdate, entity.id, entity.load_plan_id, entity.container_id, entity.sequence_order, entity.crane_id);
        if (result.affected_rows() == 0) {
            span.set_error("not found");
            throw std::runtime_error("DischargeSequence not found: " + entity.id);
        }
        tx.commit();
        span.set_status_ok();
    }

    auto remove(const std::string& id) -> void {
        DbaOperationSpan span("DischargeSequenceRepositoryImpl::remove");
        auto tx = conn_.begin();
        tx.exec_params(queries::DischargeSequenceDelete, id);
        tx.commit();
        span.set_status_ok();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<DischargeSequence> {
        DbaOperationSpan span("DischargeSequenceRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::DischargeSequenceSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        auto mapped = map_row(result[0]);
        span.set_status_ok();
        return mapped;
    }

    [[nodiscard]] auto find_all() -> std::vector<DischargeSequence> {
        DbaOperationSpan span("DischargeSequenceRepositoryImpl::find_all");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::DischargeSequenceSelectAll);
        tx.commit();
        auto out = std::vector<DischargeSequence>{ };
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        span.set_status_ok();
        return out;
    }

    /// Filter all entities by a domain specification (in-memory).
    template<typename Spec>
    [[nodiscard]] auto filter_by_spec(const Spec& spec) const -> std::vector<DischargeSequence> {
        auto all = find_all();
        auto result = std::vector<DischargeSequence>{};
        std::copy_if(all.begin(), all.end(), std::back_inserter(result),
                     [&spec](const DischargeSequence& e) { return spec.is_satisfied_by(e); });
        return result;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> DischargeSequence {
        return DischargeSequence{
            .id = row[0].as<std::string>(),
            .load_plan_id = row[1].as<boost::uuids::uuid>(),
            .container_id = row[2].as<boost::uuids::uuid>(),
            .sequence_order = row[3].as<std::int32_t>(),
            .crane_id = row[4].as<boost::uuids::uuid>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace cargo_operations
