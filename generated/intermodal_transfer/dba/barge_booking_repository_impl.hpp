#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "barge_booking.hpp"
#include "intermodal_transfer_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace intermodal_transfer {

/// Concrete CRTP repository implementation for BargeBooking.
/// Satisfies RepositoryBase<BargeBookingRepositoryImpl<C>, BargeBooking> contract.
/// Uses embedded SQL constants from intermodal_transfer_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class BargeBookingRepositoryImpl {
public:
    explicit BargeBookingRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const BargeBooking& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::BargeBookingInsert, entity.id, entity.id, entity.barge_name, entity.capacity_teu, entity.departure_at, entity.status);
        tx.commit();
    }

    auto update(const BargeBooking& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::BargeBookingUpdate, entity.id, entity.id, entity.barge_name, entity.capacity_teu, entity.departure_at, entity.status);
        if (result.affected_rows() == 0) {
            throw std::runtime_error(BargeBooking not found:  + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::BargeBookingDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<BargeBooking> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::BargeBookingSelectById, id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<BargeBooking> {
        auto tx = conn_.begin();
        auto result = tx.exec(queries::BargeBookingSelectAll);
        tx.commit();
        auto out = std::vector<BargeBooking>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
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

private:
    Connection& conn_;
;

} // namespace intermodal_transfer
