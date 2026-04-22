#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "region.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace spatial {

/// Concrete CRTP repository implementation for Region.
/// Satisfies RepositoryBase<RegionRepositoryImpl<C>, Region> contract.
/// Uses parameterised SQL (pqxx) — no stored procedures (ADR 20260120).
template<typename Connection>
class RegionRepositoryImpl {
public:
    explicit RegionRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto build_select_by_id_query() const -> std::string {
        return "SELECT id, name, boundary, center FROM spatial.region WHERE id = $1";
    }

    [[nodiscard]] auto build_insert_query() const -> std::string {
        return "INSERT INTO spatial.region (id, name, boundary, center) VALUES ($1, $2, $3, $4) RETURNING id";
    }

    [[nodiscard]] auto build_update_query() const -> std::string {
        return "UPDATE spatial.region SET name = $2, boundary = $3, center = $4 WHERE id = $1";
    }

    [[nodiscard]] auto build_delete_query() const -> std::string {
        return "DELETE FROM spatial.region WHERE id = $1";
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> Region {
        return Region{
            .id = row[0].as<std::string>(),
            .name = row[1].as<std::string>(),
            .boundary = row[2].as<std::string>(),
            .center = row[3].as<std::string>(),
        };
    }

    auto save(const Region& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_insert_query(), entity.id, entity.name, entity.boundary, entity.center);
        tx.commit();
    }

    auto update(const Region& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_update_query(), entity.id, entity.name, entity.boundary, entity.center);
        if (result.affected_rows() == 0) {
            throw std::runtime_error("Region not found: " + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_delete_query(), id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<Region> {
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
