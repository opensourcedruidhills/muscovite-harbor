#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "discharge_sequence.hpp"
#include "cargo_operations_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace cargo_operations {

/// Concrete CRTP repository implementation for DischargeSequence.
/// Satisfies RepositoryBase<DischargeSequenceRepositoryImpl<C>, DischargeSequence> contract.
/// Uses embedded SQL constants from cargo_operations_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class DischargeSequenceRepositoryImpl {
public:
    explicit DischargeSequenceRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const DischargeSequence& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::DischargeSequenceInsert, entity.id, entity.id, entity.load_plan_id, entity.container_id, entity.sequence_order, entity.crane_id);
        tx.commit();
    }

    auto update(const DischargeSequence& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::DischargeSequenceUpdate, entity.id, entity.id, entity.load_plan_id, entity.container_id, entity.sequence_order, entity.crane_id);
        if (result.affected_rows() == 0) {
            throw std::runtime_error(DischargeSequence not found:  + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::DischargeSequenceDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<DischargeSequence> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::DischargeSequenceSelectById, id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<DischargeSequence> {
        auto tx = conn_.begin();
        auto result = tx.exec(queries::DischargeSequenceSelectAll);
        tx.commit();
        auto out = std::vector<DischargeSequence>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> DischargeSequence {
        return DischargeSequence{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .load_plan_id = row[2].as<std::string>(),
            .container_id = row[3].as<std::string>(),
            .sequence_order = row[4].as<std::string>(),
            .crane_id = row[5].as<std::string>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace cargo_operations
