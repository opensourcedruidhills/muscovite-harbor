#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "spatial_projection.hpp"
#include "spatial_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace spatial {

/// Concrete CRTP repository implementation for SpatialProjection.
/// Satisfies RepositoryBase<SpatialProjectionRepositoryImpl<C>, SpatialProjection> contract.
/// Uses embedded SQL constants from spatial_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class SpatialProjectionRepositoryImpl {
public:
    explicit SpatialProjectionRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const SpatialProjection& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::SpatialProjectionInsert, entity.id, entity.name, entity.srid, entity.definition);
        tx.commit();
    }

    auto update(const SpatialProjection& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::SpatialProjectionUpdate, entity.id, entity.name, entity.srid, entity.definition);
        if (result.affected_rows() == 0) {
            throw std::runtime_error(SpatialProjection not found:  + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::SpatialProjectionDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<SpatialProjection> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::SpatialProjectionSelectById, id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<SpatialProjection> {
        auto tx = conn_.begin();
        auto result = tx.exec(queries::SpatialProjectionSelectAll);
        tx.commit();
        auto out = std::vector<SpatialProjection>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> SpatialProjection {
        return SpatialProjection{
            .id = row[0].as<std::string>(),
            .name = row[1].as<std::string>(),
            .srid = row[2].as<std::string>(),
            .definition = row[3].as<std::string>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace spatial
