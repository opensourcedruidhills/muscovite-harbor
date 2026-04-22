#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "barge_booking.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace intermodal_transfer {

/// Concrete CRTP repository implementation for BargeBooking.
/// Satisfies RepositoryBase<BargeBookingRepositoryImpl<C>, BargeBooking> contract.
/// Uses parameterised SQL (pqxx) — no stored procedures (ADR 20260120).
template<typename Connection>
class BargeBookingRepositoryImpl {
public:
    explicit BargeBookingRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto build_select_by_id_query() const -> std::string {
        return "SELECT id, id, barge_name, capacity_teu, departure_at, status FROM intermodal_transfer.barge_booking WHERE id = $1";
    }

    [[nodiscard]] auto build_insert_query() const -> std::string {
        return "INSERT INTO intermodal_transfer.barge_booking (id, id, barge_name, capacity_teu, departure_at, status) VALUES ($1, $2, $3, $4, $5, $6) RETURNING id";
    }

    [[nodiscard]] auto build_update_query() const -> std::string {
        return "UPDATE intermodal_transfer.barge_booking SET id = $2, barge_name = $3, capacity_teu = $4, departure_at = $5, status = $6 WHERE id = $1";
    }

    [[nodiscard]] auto build_delete_query() const -> std::string {
        return "DELETE FROM intermodal_transfer.barge_booking WHERE id = $1";
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> BargeBooking {
        return BargeBooking{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .barge_name = row[2].as<std::string>(),
            .capacity_teu = row[3].as<std::string>(),
            .departure_at = row[4].as<std::string>(),
            .status = row[5].as<std::string>(),
        };
    }

    auto save(const BargeBooking& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_insert_query(), entity.id, entity.id, entity.barge_name, entity.capacity_teu, entity.departure_at, entity.status);
        tx.commit();
    }

    auto update(const BargeBooking& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_update_query(), entity.id, entity.id, entity.barge_name, entity.capacity_teu, entity.departure_at, entity.status);
        if (result.affected_rows() == 0) {
            throw std::runtime_error("BargeBooking not found: " + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_delete_query(), id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<BargeBooking> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_select_by_id_query(), id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

private:
    Connection& conn_;
};

} // namespace intermodal_transfer
