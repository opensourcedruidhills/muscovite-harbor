#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "coordinate.hpp"
#include "spatial_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace spatial {

/// Concrete CRTP repository implementation for Coordinate.
/// Satisfies RepositoryBase<CoordinateRepositoryImpl<C>, Coordinate> contract.
/// Uses embedded SQL constants from spatial_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class CoordinateRepositoryImpl {
public:
    explicit CoordinateRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const Coordinate& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::CoordinateInsert, entity.id, entity.latitude, entity.longitude, entity.altitude, entity.srid);
        tx.commit();
    }

    auto update(const Coordinate& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::CoordinateUpdate, entity.id, entity.latitude, entity.longitude, entity.altitude, entity.srid);
        if (result.affected_rows() == 0) {
            throw std::runtime_error(Coordinate not found:  + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::CoordinateDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<Coordinate> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::CoordinateSelectById, id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<Coordinate> {
        auto tx = conn_.begin();
        auto result = tx.exec(queries::CoordinateSelectAll);
        tx.commit();
        auto out = std::vector<Coordinate>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
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

private:
    Connection& conn_;
;

} // namespace spatial
