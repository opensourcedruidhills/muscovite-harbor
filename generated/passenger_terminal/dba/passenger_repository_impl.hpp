#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "passenger.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace passenger_terminal {

/// Concrete CRTP repository implementation for Passenger.
/// Satisfies RepositoryBase<PassengerRepositoryImpl<C>, Passenger> contract.
/// Uses parameterised SQL (pqxx) — no stored procedures (ADR 20260120).
template<typename Connection>
class PassengerRepositoryImpl {
public:
    explicit PassengerRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto build_select_by_id_query() const -> std::string {
        return "SELECT id, id, booking_ref, passenger_type, voyage_id, status FROM passenger_terminal.passenger WHERE id = $1";
    }

    [[nodiscard]] auto build_insert_query() const -> std::string {
        return "INSERT INTO passenger_terminal.passenger (id, id, booking_ref, passenger_type, voyage_id, status) VALUES ($1, $2, $3, $4, $5, $6) RETURNING id";
    }

    [[nodiscard]] auto build_update_query() const -> std::string {
        return "UPDATE passenger_terminal.passenger SET id = $2, booking_ref = $3, passenger_type = $4, voyage_id = $5, status = $6 WHERE id = $1";
    }

    [[nodiscard]] auto build_delete_query() const -> std::string {
        return "DELETE FROM passenger_terminal.passenger WHERE id = $1";
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> Passenger {
        return Passenger{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .booking_ref = row[2].as<std::string>(),
            .passenger_type = row[3].as<std::string>(),
            .voyage_id = row[4].as<std::string>(),
            .status = row[5].as<std::string>(),
        };
    }

    auto save(const Passenger& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_insert_query(), entity.id, entity.id, entity.booking_ref, entity.passenger_type, entity.voyage_id, entity.status);
        tx.commit();
    }

    auto update(const Passenger& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_update_query(), entity.id, entity.id, entity.booking_ref, entity.passenger_type, entity.voyage_id, entity.status);
        if (result.affected_rows() == 0) {
            throw std::runtime_error("Passenger not found: " + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_delete_query(), id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<Passenger> {
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
