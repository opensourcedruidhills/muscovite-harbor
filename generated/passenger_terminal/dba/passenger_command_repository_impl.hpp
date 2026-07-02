#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "passenger_command_repository.hpp"
#include "passenger_terminal_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>

namespace passenger_terminal {

class DbaOperationSpan {
public:
    explicit DbaOperationSpan(std::string_view operation) : operation_{operation} {}
    auto set_status_ok() noexcept -> void {}
    auto set_error(std::string_view /*message*/) noexcept -> void {}
private:
    std::string_view operation_;
};

/// pqxx-based command repository implementation for Passenger aggregate.
/// Uses embedded SQL constants from passenger_terminal_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class PassengerCommandRepositoryImpl : public PassengerCommandRepository {
public:
    explicit PassengerCommandRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const Passenger& entity) -> void override {
        DbaOperationSpan span("PassengerCommandRepositoryImpl::save");
        auto tx = conn_.begin();
        tx.exec_params(queries::PassengerUpsert,
            entity.id, entity.booking_ref, entity.passenger_type, entity.voyage_id, entity.status);
        tx.commit();
        span.set_status_ok();
    }

    auto update(const Passenger& entity) -> void override {
        DbaOperationSpan span("PassengerCommandRepositoryImpl::update");
        auto tx = conn_.begin();
        tx.exec_params(queries::PassengerUpdate,
            entity.id, entity.booking_ref, entity.passenger_type, entity.voyage_id, entity.status);
        tx.commit();
        span.set_status_ok();
    }

    auto remove(const Passenger::Id& id) -> void override {
        DbaOperationSpan span("PassengerCommandRepositoryImpl::remove");
        auto tx = conn_.begin();
        tx.exec_params(queries::PassengerDelete, id);
        tx.commit();
        span.set_status_ok();
    }

    [[nodiscard]] auto find_by_id(const Passenger::Id& id) -> std::optional<Passenger> override {
        DbaOperationSpan span("PassengerCommandRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::PassengerSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        const auto& row = result[0];
        auto entity = Passenger{
            .id = row[0].as<std::string>(),
            .booking_ref = row[1].as<std::string>(),
            .passenger_type = row[2].as<std::string>(),
            .voyage_id = row[3].as<boost::uuids::uuid>(),
            .status = row[4].as<std::string>(),
        };
        span.set_status_ok();
        return entity;
    }

private:
    Connection& conn_;
;

} // namespace passenger_terminal
