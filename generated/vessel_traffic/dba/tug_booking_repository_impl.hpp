#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "tug_booking.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace vessel_traffic {

/// Concrete CRTP repository implementation for TugBooking.
/// Satisfies RepositoryBase<TugBookingRepositoryImpl<C>, TugBooking> contract.
/// Uses parameterised SQL (pqxx) — no stored procedures (ADR 20260120).
template<typename Connection>
class TugBookingRepositoryImpl {
public:
    explicit TugBookingRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto build_select_by_id_query() const -> std::string {
        return "SELECT id, id, voyage_id, tug_name, bollard_pull_t, is_confirmed FROM vessel_traffic.tug_booking WHERE id = $1";
    }

    [[nodiscard]] auto build_insert_query() const -> std::string {
        return "INSERT INTO vessel_traffic.tug_booking (id, id, voyage_id, tug_name, bollard_pull_t, is_confirmed) VALUES ($1, $2, $3, $4, $5, $6) RETURNING id";
    }

    [[nodiscard]] auto build_update_query() const -> std::string {
        return "UPDATE vessel_traffic.tug_booking SET id = $2, voyage_id = $3, tug_name = $4, bollard_pull_t = $5, is_confirmed = $6 WHERE id = $1";
    }

    [[nodiscard]] auto build_delete_query() const -> std::string {
        return "DELETE FROM vessel_traffic.tug_booking WHERE id = $1";
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> TugBooking {
        return TugBooking{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .voyage_id = row[2].as<std::string>(),
            .tug_name = row[3].as<std::string>(),
            .bollard_pull_t = row[4].as<std::string>(),
            .is_confirmed = row[5].as<std::string>(),
        };
    }

    auto save(const TugBooking& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_insert_query(), entity.id, entity.id, entity.voyage_id, entity.tug_name, entity.bollard_pull_t, entity.is_confirmed);
        tx.commit();
    }

    auto update(const TugBooking& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_update_query(), entity.id, entity.id, entity.voyage_id, entity.tug_name, entity.bollard_pull_t, entity.is_confirmed);
        if (result.affected_rows() == 0) {
            throw std::runtime_error("TugBooking not found: " + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_delete_query(), id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<TugBooking> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_select_by_id_query(), id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

private:
    Connection& conn_;
};

} // namespace vessel_traffic
