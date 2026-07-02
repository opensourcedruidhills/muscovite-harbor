#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "tug_booking.hpp"
#include "vessel_traffic_queries.hpp"
#include <algorithm>
#include <iterator>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>

namespace vessel_traffic {

class DbaOperationSpan {
public:
    explicit DbaOperationSpan(std::string_view operation) : operation_{operation} {}
    auto set_status_ok() noexcept -> void {}
    auto set_error(std::string_view /*message*/) noexcept -> void {}
private:
    std::string_view operation_;
};

/// Concrete CRTP repository implementation for TugBooking.
/// Satisfies RepositoryBase<TugBookingRepositoryImpl<C>, TugBooking> contract.
/// Uses embedded SQL constants from vessel_traffic_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class TugBookingRepositoryImpl {
public:
    explicit TugBookingRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const TugBooking& entity) -> void {
        DbaOperationSpan span("TugBookingRepositoryImpl::save");
        auto tx = conn_.begin();
        tx.exec_params(queries::TugBookingInsert, entity.id, entity.voyage_id, entity.tug_name, entity.bollard_pull_t, entity.is_confirmed);
        tx.commit();
        span.set_status_ok();
    }

    auto update(const TugBooking& entity) -> void {
        DbaOperationSpan span("TugBookingRepositoryImpl::update");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::TugBookingUpdate, entity.id, entity.voyage_id, entity.tug_name, entity.bollard_pull_t, entity.is_confirmed);
        if (result.affected_rows() == 0) {
            span.set_error("not found");
            throw std::runtime_error("TugBooking not found: " + entity.id);
        }
        tx.commit();
        span.set_status_ok();
    }

    auto remove(const std::string& id) -> void {
        DbaOperationSpan span("TugBookingRepositoryImpl::remove");
        auto tx = conn_.begin();
        tx.exec_params(queries::TugBookingDelete, id);
        tx.commit();
        span.set_status_ok();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<TugBooking> {
        DbaOperationSpan span("TugBookingRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::TugBookingSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        auto mapped = map_row(result[0]);
        span.set_status_ok();
        return mapped;
    }

    [[nodiscard]] auto find_all() -> std::vector<TugBooking> {
        DbaOperationSpan span("TugBookingRepositoryImpl::find_all");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::TugBookingSelectAll);
        tx.commit();
        auto out = std::vector<TugBooking>{ };
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        span.set_status_ok();
        return out;
    }

    /// Filter all entities by a domain specification (in-memory).
    template<typename Spec>
    [[nodiscard]] auto filter_by_spec(const Spec& spec) const -> std::vector<TugBooking> {
        auto all = find_all();
        auto result = std::vector<TugBooking>{};
        std::copy_if(all.begin(), all.end(), std::back_inserter(result),
                     [&spec](const TugBooking& e) { return spec.is_satisfied_by(e); });
        return result;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> TugBooking {
        return TugBooking{
            .id = row[0].as<std::string>(),
            .voyage_id = row[1].as<boost::uuids::uuid>(),
            .tug_name = row[2].as<std::string>(),
            .bollard_pull_t = row[3].as<muscovite::dba::Decimal>(),
            .is_confirmed = row[4].as<bool>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace vessel_traffic
