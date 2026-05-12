#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "tug_booking.hpp"
#include "vessel_traffic_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace vessel_traffic {

/// Concrete CRTP repository implementation for TugBooking.
/// Satisfies RepositoryBase<TugBookingRepositoryImpl<C>, TugBooking> contract.
/// Uses embedded SQL constants from vessel_traffic_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class TugBookingRepositoryImpl {
public:
    explicit TugBookingRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const TugBooking& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::TugBookingInsert, entity.id, entity.id, entity.voyage_id, entity.tug_name, entity.bollard_pull_t, entity.is_confirmed);
        tx.commit();
    }

    auto update(const TugBooking& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::TugBookingUpdate, entity.id, entity.id, entity.voyage_id, entity.tug_name, entity.bollard_pull_t, entity.is_confirmed);
        if (result.affected_rows() == 0) {
            throw std::runtime_error(TugBooking not found:  + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::TugBookingDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<TugBooking> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::TugBookingSelectById, id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<TugBooking> {
        auto tx = conn_.begin();
        auto result = tx.exec(queries::TugBookingSelectAll);
        tx.commit();
        auto out = std::vector<TugBooking>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
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

private:
    Connection& conn_;
;

} // namespace vessel_traffic
