#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "boarding_pass.hpp"
#include "passenger_terminal_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace passenger_terminal {

/// Concrete CRTP repository implementation for BoardingPass.
/// Satisfies RepositoryBase<BoardingPassRepositoryImpl<C>, BoardingPass> contract.
/// Uses embedded SQL constants from passenger_terminal_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class BoardingPassRepositoryImpl {
public:
    explicit BoardingPassRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const BoardingPass& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::BoardingPassInsert, entity.id, entity.id, entity.passenger_id, entity.gate_id, entity.boarding_group, entity.seat_number, entity.issued_at, entity.scanned_at);
        tx.commit();
    }

    auto update(const BoardingPass& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::BoardingPassUpdate, entity.id, entity.id, entity.passenger_id, entity.gate_id, entity.boarding_group, entity.seat_number, entity.issued_at, entity.scanned_at);
        if (result.affected_rows() == 0) {
            throw std::runtime_error(BoardingPass not found:  + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::BoardingPassDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<BoardingPass> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::BoardingPassSelectById, id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<BoardingPass> {
        auto tx = conn_.begin();
        auto result = tx.exec(queries::BoardingPassSelectAll);
        tx.commit();
        auto out = std::vector<BoardingPass>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> BoardingPass {
        return BoardingPass{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .passenger_id = row[2].as<std::string>(),
            .gate_id = row[3].as<std::string>(),
            .boarding_group = row[4].as<std::string>(),
            .seat_number = row[5].as<std::string>(),
            .issued_at = row[6].as<std::string>(),
            .scanned_at = row[7].as<std::string>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace passenger_terminal
