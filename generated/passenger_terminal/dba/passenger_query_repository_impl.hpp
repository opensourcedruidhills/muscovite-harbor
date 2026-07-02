#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "passenger_query_repository.hpp"
#include "passenger_terminal_queries.hpp"
#include <cstdint>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

namespace passenger_terminal {

class DbaOperationSpan {
public:
    explicit DbaOperationSpan(std::string_view operation) : operation_{operation} {}
    auto set_status_ok() noexcept -> void {}
    auto set_error(std::string_view /*message*/) noexcept -> void {}
private:
    std::string_view operation_;
};

/// pqxx-based query repository implementation for Passenger aggregate.
/// Uses embedded SQL constants from passenger_terminal_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class PassengerQueryRepositoryImpl : public PassengerQueryRepository {
public:
    explicit PassengerQueryRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto find_by_id(const Passenger::Id& id) -> std::optional<Passenger> override {
        DbaOperationSpan span("PassengerQueryRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::PassengerSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        auto mapped = map_row(result[0]);
        span.set_status_ok();
        return mapped;
    }

    [[nodiscard]] auto find_all() -> std::vector<Passenger> override {
        DbaOperationSpan span("PassengerQueryRepositoryImpl::find_all");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::PassengerSelectAll);
        tx.commit();
        auto out = std::vector<Passenger>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        span.set_status_ok();
        return out;
    }

    [[nodiscard]] auto count() -> std::int64_t override {
        DbaOperationSpan span("PassengerQueryRepositoryImpl::count");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::PassengerCount);
        tx.commit();
        auto total = result[0][0].as<std::int64_t>();
        span.set_status_ok();
        return total;
    }

private:
    Connection& conn_;

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> Passenger {
        return Passenger{
            .id = row[0].as<std::string>(),
            .id = row[1].as<boost::uuids::uuid>(),
            .booking_ref = row[2].as<std::string>(),
            .passenger_type = row[3].as<std::string>(),
            .voyage_id = row[4].as<boost::uuids::uuid>(),
            .status = row[5].as<std::string>(),
        };
    }
;

} // namespace passenger_terminal
