#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "passenger_command_repository.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace passenger_terminal {

/// pqxx-based command repository implementation for Passenger aggregate.
/// Uses direct parameterised SQL — no stored procedures (ADR 20260120).
template<typename Connection>
class PassengerCommandRepositoryImpl : public PassengerCommandRepository {
public:
    explicit PassengerCommandRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const Passenger& entity) -> void override {
        auto tx = conn_.begin();
        tx.exec_params("INSERT INTO passenger_terminal.passenger (id, id, booking_ref, passenger_type, voyage_id, status) VALUES ($1, $2, $3, $4, $5, $6) ON CONFLICT (id) DO UPDATE SET id = $2, booking_ref = $3, passenger_type = $4, voyage_id = $5, status = $6",
            entity.id, entity.id, entity.booking_ref, entity.passenger_type, entity.voyage_id, entity.status);
        tx.commit();
    }

    auto remove(const Passenger::Id& id) -> void override {
        auto tx = conn_.begin();
        tx.exec_params("DELETE FROM passenger_terminal.passenger WHERE id = $1", id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const Passenger::Id& id) -> std::optional<Passenger> override {
        auto tx = conn_.begin();
        auto result = tx.exec_params("SELECT id, id, booking_ref, passenger_type, voyage_id, status FROM passenger_terminal.passenger WHERE id = $1", id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        const auto& row = result[0];
        return Passenger{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .booking_ref = row[2].as<std::string>(),
            .passenger_type = row[3].as<std::string>(),
            .voyage_id = row[4].as<std::string>(),
            .status = row[5].as<std::string>(),
        };
    }

private:
    Connection& conn_;
};

} // namespace passenger_terminal
