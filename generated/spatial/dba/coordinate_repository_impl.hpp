#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "coordinate.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace spatial {

/// Concrete CRTP repository implementation for Coordinate.
/// Satisfies RepositoryBase<CoordinateRepositoryImpl<C>, Coordinate> contract.
/// Uses parameterised SQL (pqxx) — no stored procedures (ADR 20260120).
template<typename Connection>
class CoordinateRepositoryImpl {
public:
    explicit CoordinateRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto build_select_by_id_query() const -> std::string {
        return "SELECT id, latitude, longitude, altitude, srid FROM spatial.coordinate WHERE id = $1";
    }

    [[nodiscard]] auto build_insert_query() const -> std::string {
        return "INSERT INTO spatial.coordinate (id, latitude, longitude, altitude, srid) VALUES ($1, $2, $3, $4, $5) RETURNING id";
    }

    [[nodiscard]] auto build_update_query() const -> std::string {
        return "UPDATE spatial.coordinate SET latitude = $2, longitude = $3, altitude = $4, srid = $5 WHERE id = $1";
    }

    [[nodiscard]] auto build_delete_query() const -> std::string {
        return "DELETE FROM spatial.coordinate WHERE id = $1";
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> Coordinate {
        return Coordinate{
            .id = row[0].as<std::string>(),
            .latitude = row[1].as<std::string>(),
            .longitude = row[2].as<std::string>(),
            .altitude = row[3].as<std::string>(),
            .srid = row[4].as<std::string>(),
        };
    }

    auto save(const Coordinate& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_insert_query(), entity.id, entity.latitude, entity.longitude, entity.altitude, entity.srid);
        tx.commit();
    }

    auto update(const Coordinate& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_update_query(), entity.id, entity.latitude, entity.longitude, entity.altitude, entity.srid);
        if (result.affected_rows() == 0) {
            throw std::runtime_error("Coordinate not found: " + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_delete_query(), id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<Coordinate> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_select_by_id_query(), id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

private:
    Connection& conn_;
};

} // namespace spatial
