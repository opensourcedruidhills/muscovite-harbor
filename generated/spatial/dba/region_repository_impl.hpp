#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "region.hpp"
#include "spatial_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace spatial {

/// Concrete CRTP repository implementation for Region.
/// Satisfies RepositoryBase<RegionRepositoryImpl<C>, Region> contract.
/// Uses embedded SQL constants from spatial_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class RegionRepositoryImpl {
public:
    explicit RegionRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const Region& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::RegionInsert, entity.id, entity.name, entity.boundary, entity.center);
        tx.commit();
    }

    auto update(const Region& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::RegionUpdate, entity.id, entity.name, entity.boundary, entity.center);
        if (result.affected_rows() == 0) {
            throw std::runtime_error(Region not found:  + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::RegionDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<Region> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::RegionSelectById, id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<Region> {
        auto tx = conn_.begin();
        auto result = tx.exec(queries::RegionSelectAll);
        tx.commit();
        auto out = std::vector<Region>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> Region {
        return Region{
            .id = row[0].as<std::string>(),
            .name = row[1].as<std::string>(),
            .boundary = row[2].as<std::string>(),
            .center = row[3].as<std::string>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace spatial
