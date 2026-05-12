#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "container.hpp"
#include "cargo_operations_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace cargo_operations {

/// Concrete CRTP repository implementation for Container.
/// Satisfies RepositoryBase<ContainerRepositoryImpl<C>, Container> contract.
/// Uses embedded SQL constants from cargo_operations_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class ContainerRepositoryImpl {
public:
    explicit ContainerRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const Container& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::ContainerInsert, entity.id, entity.id, entity.container_number, entity.size_category, entity.hazmat_class, entity.voyage_id, entity.yard_slot_id, entity.status);
        tx.commit();
    }

    auto update(const Container& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::ContainerUpdate, entity.id, entity.id, entity.container_number, entity.size_category, entity.hazmat_class, entity.voyage_id, entity.yard_slot_id, entity.status);
        if (result.affected_rows() == 0) {
            throw std::runtime_error(Container not found:  + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::ContainerDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<Container> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::ContainerSelectById, id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<Container> {
        auto tx = conn_.begin();
        auto result = tx.exec(queries::ContainerSelectAll);
        tx.commit();
        auto out = std::vector<Container>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> Container {
        return Container{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .container_number = row[2].as<std::string>(),
            .size_category = row[3].as<std::string>(),
            .hazmat_class = row[4].as<std::string>(),
            .voyage_id = row[5].as<std::string>(),
            .yard_slot_id = row[6].as<std::string>(),
            .status = row[7].as<std::string>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace cargo_operations
