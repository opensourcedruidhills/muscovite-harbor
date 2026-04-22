#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "spatial_projection.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace spatial {

/// Concrete CRTP repository implementation for SpatialProjection.
/// Satisfies RepositoryBase<SpatialProjectionRepositoryImpl<C>, SpatialProjection> contract.
/// Uses parameterised SQL (pqxx) — no stored procedures (ADR 20260120).
template<typename Connection>
class SpatialProjectionRepositoryImpl {
public:
    explicit SpatialProjectionRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto build_select_by_id_query() const -> std::string {
        return "SELECT id, name, srid, definition FROM spatial.spatial_projection WHERE id = $1";
    }

    [[nodiscard]] auto build_insert_query() const -> std::string {
        return "INSERT INTO spatial.spatial_projection (id, name, srid, definition) VALUES ($1, $2, $3, $4) RETURNING id";
    }

    [[nodiscard]] auto build_update_query() const -> std::string {
        return "UPDATE spatial.spatial_projection SET name = $2, srid = $3, definition = $4 WHERE id = $1";
    }

    [[nodiscard]] auto build_delete_query() const -> std::string {
        return "DELETE FROM spatial.spatial_projection WHERE id = $1";
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> SpatialProjection {
        return SpatialProjection{
            .id = row[0].as<std::string>(),
            .name = row[1].as<std::string>(),
            .srid = row[2].as<std::string>(),
            .definition = row[3].as<std::string>(),
        };
    }

    auto save(const SpatialProjection& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_insert_query(), entity.id, entity.name, entity.srid, entity.definition);
        tx.commit();
    }

    auto update(const SpatialProjection& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_update_query(), entity.id, entity.name, entity.srid, entity.definition);
        if (result.affected_rows() == 0) {
            throw std::runtime_error("SpatialProjection not found: " + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_delete_query(), id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<SpatialProjection> {
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
