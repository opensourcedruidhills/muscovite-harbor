#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "boarding_pass.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace passenger_terminal {

/// Concrete CRTP repository implementation for BoardingPass.
/// Satisfies RepositoryBase<BoardingPassRepositoryImpl<C>, BoardingPass> contract.
/// Uses parameterised SQL (pqxx) — no stored procedures (ADR 20260120).
template<typename Connection>
class BoardingPassRepositoryImpl {
public:
    explicit BoardingPassRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto build_select_by_id_query() const -> std::string {
        return "SELECT id, id, passenger_id, gate_id, boarding_group, seat_number, issued_at, scanned_at FROM passenger_terminal.boarding_pass WHERE id = $1";
    }

    [[nodiscard]] auto build_insert_query() const -> std::string {
        return "INSERT INTO passenger_terminal.boarding_pass (id, id, passenger_id, gate_id, boarding_group, seat_number, issued_at, scanned_at) VALUES ($1, $2, $3, $4, $5, $6, $7, $8) RETURNING id";
    }

    [[nodiscard]] auto build_update_query() const -> std::string {
        return "UPDATE passenger_terminal.boarding_pass SET id = $2, passenger_id = $3, gate_id = $4, boarding_group = $5, seat_number = $6, issued_at = $7, scanned_at = $8 WHERE id = $1";
    }

    [[nodiscard]] auto build_delete_query() const -> std::string {
        return "DELETE FROM passenger_terminal.boarding_pass WHERE id = $1";
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

    auto save(const BoardingPass& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_insert_query(), entity.id, entity.id, entity.passenger_id, entity.gate_id, entity.boarding_group, entity.seat_number, entity.issued_at, entity.scanned_at);
        tx.commit();
    }

    auto update(const BoardingPass& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_update_query(), entity.id, entity.id, entity.passenger_id, entity.gate_id, entity.boarding_group, entity.seat_number, entity.issued_at, entity.scanned_at);
        if (result.affected_rows() == 0) {
            throw std::runtime_error("BoardingPass not found: " + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_delete_query(), id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<BoardingPass> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_select_by_id_query(), id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

private:
    Connection& conn_;
};

} // namespace passenger_terminal
