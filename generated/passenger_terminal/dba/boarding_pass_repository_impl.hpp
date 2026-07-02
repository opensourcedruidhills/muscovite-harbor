#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "boarding_pass.hpp"
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

/// Concrete CRTP repository implementation for BoardingPass.
/// Satisfies RepositoryBase<BoardingPassRepositoryImpl<C>, BoardingPass> contract.
/// Uses embedded SQL constants from passenger_terminal_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class BoardingPassRepositoryImpl {
public:
    explicit BoardingPassRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const BoardingPass& entity) -> void {
        DbaOperationSpan span("BoardingPassRepositoryImpl::save");
        auto tx = conn_.begin();
        tx.exec_params(queries::BoardingPassInsert, entity.id, entity.passenger_id, entity.gate_id, entity.boarding_group, entity.seat_number, entity.issued_at, entity.scanned_at);
        tx.commit();
        span.set_status_ok();
    }

    auto update(const BoardingPass& entity) -> void {
        DbaOperationSpan span("BoardingPassRepositoryImpl::update");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::BoardingPassUpdate, entity.id, entity.passenger_id, entity.gate_id, entity.boarding_group, entity.seat_number, entity.issued_at, entity.scanned_at);
        if (result.affected_rows() == 0) {
            span.set_error("not found");
            throw std::runtime_error("BoardingPass not found: " + entity.id);
        }
        tx.commit();
        span.set_status_ok();
    }

    auto remove(const std::string& id) -> void {
        DbaOperationSpan span("BoardingPassRepositoryImpl::remove");
        auto tx = conn_.begin();
        tx.exec_params(queries::BoardingPassDelete, id);
        tx.commit();
        span.set_status_ok();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<BoardingPass> {
        DbaOperationSpan span("BoardingPassRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::BoardingPassSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        auto mapped = map_row(result[0]);
        span.set_status_ok();
        return mapped;
    }

    [[nodiscard]] auto find_all() -> std::vector<BoardingPass> {
        DbaOperationSpan span("BoardingPassRepositoryImpl::find_all");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::BoardingPassSelectAll);
        tx.commit();
        auto out = std::vector<BoardingPass>{ };
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        span.set_status_ok();
        return out;
    }

    /// Filter all entities by a domain specification (in-memory).
    template<typename Spec>
    [[nodiscard]] auto filter_by_spec(const Spec& spec) const -> std::vector<BoardingPass> {
        auto all = find_all();
        auto result = std::vector<BoardingPass>{};
        std::copy_if(all.begin(), all.end(), std::back_inserter(result),
                     [&spec](const BoardingPass& e) { return spec.is_satisfied_by(e); });
        return result;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> BoardingPass {
        return BoardingPass{
            .id = row[0].as<std::string>(),
            .passenger_id = row[1].as<boost::uuids::uuid>(),
            .gate_id = row[2].as<boost::uuids::uuid>(),
            .boarding_group = row[3].as<std::string>(),
            .seat_number = row[4].as<std::string>(),
            .issued_at = row[5].as<muscovite::dba::Timestamp>(),
            .scanned_at = row[6].as<muscovite::dba::Timestamp>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace passenger_terminal
