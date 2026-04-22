#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "passenger_query_repository.hpp"
#include <cstdint>
#include <optional>
#include <stdexcept>
#include <string>
#include <vector>

namespace passenger_terminal {

/// pqxx-based query repository implementation for Passenger aggregate.
/// Uses direct parameterised SQL — no stored procedures (ADR 20260120).
template<typename Connection>
class PassengerQueryRepositoryImpl : public PassengerQueryRepository {
public:
    explicit PassengerQueryRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto find_by_id(const Passenger::Id& id) -> std::optional<Passenger> override {
        auto tx = conn_.begin();
        auto result = tx.exec_params("SELECT id, id, booking_ref, passenger_type, voyage_id, status FROM passenger_terminal.passenger WHERE id = $1", id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<Passenger> override {
        auto tx = conn_.begin();
        auto result = tx.exec("SELECT id, id, booking_ref, passenger_type, voyage_id, status FROM passenger_terminal.passenger ORDER BY id");
        tx.commit();
        auto out = std::vector<Passenger>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
    }

    [[nodiscard]] auto count() -> std::int64_t override {
        auto tx = conn_.begin();
        auto result = tx.exec("SELECT COUNT(*) FROM passenger_terminal.passenger");
        tx.commit();
        return result[0][0].as<std::int64_t>();
    }

private:
    Connection& conn_;

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
};

} // namespace passenger_terminal
