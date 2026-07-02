#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "barge_booking.hpp"
#include "intermodal_transfer_queries.hpp"
#include <algorithm>
#include <iterator>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>

namespace intermodal_transfer {

class DbaOperationSpan {
public:
    explicit DbaOperationSpan(std::string_view operation) : operation_{operation} {}
    auto set_status_ok() noexcept -> void {}
    auto set_error(std::string_view /*message*/) noexcept -> void {}
private:
    std::string_view operation_;
};

/// Concrete CRTP repository implementation for BargeBooking.
/// Satisfies RepositoryBase<BargeBookingRepositoryImpl<C>, BargeBooking> contract.
/// Uses embedded SQL constants from intermodal_transfer_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class BargeBookingRepositoryImpl {
public:
    explicit BargeBookingRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const BargeBooking& entity) -> void {
        DbaOperationSpan span("BargeBookingRepositoryImpl::save");
        auto tx = conn_.begin();
        tx.exec_params(queries::BargeBookingInsert, entity.id, entity.barge_name, entity.capacity_teu, entity.departure_at, entity.status);
        tx.commit();
        span.set_status_ok();
    }

    auto update(const BargeBooking& entity) -> void {
        DbaOperationSpan span("BargeBookingRepositoryImpl::update");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::BargeBookingUpdate, entity.id, entity.barge_name, entity.capacity_teu, entity.departure_at, entity.status);
        if (result.affected_rows() == 0) {
            span.set_error("not found");
            throw std::runtime_error("BargeBooking not found: " + entity.id);
        }
        tx.commit();
        span.set_status_ok();
    }

    auto remove(const std::string& id) -> void {
        DbaOperationSpan span("BargeBookingRepositoryImpl::remove");
        auto tx = conn_.begin();
        tx.exec_params(queries::BargeBookingDelete, id);
        tx.commit();
        span.set_status_ok();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<BargeBooking> {
        DbaOperationSpan span("BargeBookingRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::BargeBookingSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        auto mapped = map_row(result[0]);
        span.set_status_ok();
        return mapped;
    }

    [[nodiscard]] auto find_all() -> std::vector<BargeBooking> {
        DbaOperationSpan span("BargeBookingRepositoryImpl::find_all");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::BargeBookingSelectAll);
        tx.commit();
        auto out = std::vector<BargeBooking>{ };
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        span.set_status_ok();
        return out;
    }

    /// Filter all entities by a domain specification (in-memory).
    template<typename Spec>
    [[nodiscard]] auto filter_by_spec(const Spec& spec) const -> std::vector<BargeBooking> {
        auto all = find_all();
        auto result = std::vector<BargeBooking>{};
        std::copy_if(all.begin(), all.end(), std::back_inserter(result),
                     [&spec](const BargeBooking& e) { return spec.is_satisfied_by(e); });
        return result;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> BargeBooking {
        return BargeBooking{
            .id = row[0].as<std::string>(),
            .barge_name = row[1].as<std::string>(),
            .capacity_teu = row[2].as<std::int32_t>(),
            .departure_at = row[3].as<muscovite::dba::Timestamp>(),
            .status = row[4].as<std::string>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace intermodal_transfer
