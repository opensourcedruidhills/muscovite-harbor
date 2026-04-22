#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "container_query_repository.hpp"
#include <cstdint>
#include <optional>
#include <stdexcept>
#include <string>
#include <vector>

namespace cargo_operations {

/// pqxx-based query repository implementation for Container aggregate.
/// Uses direct parameterised SQL — no stored procedures (ADR 20260120).
template<typename Connection>
class ContainerQueryRepositoryImpl : public ContainerQueryRepository {
public:
    explicit ContainerQueryRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto find_by_id(const Container::Id& id) -> std::optional<Container> override {
        auto tx = conn_.begin();
        auto result = tx.exec_params("SELECT id, id, container_number, size_category, hazmat_class, voyage_id, yard_slot_id, status FROM cargo_operations.container WHERE id = $1", id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<Container> override {
        auto tx = conn_.begin();
        auto result = tx.exec("SELECT id, id, container_number, size_category, hazmat_class, voyage_id, yard_slot_id, status FROM cargo_operations.container ORDER BY id");
        tx.commit();
        auto out = std::vector<Container>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
    }

    [[nodiscard]] auto count() -> std::int64_t override {
        auto tx = conn_.begin();
        auto result = tx.exec("SELECT COUNT(*) FROM cargo_operations.container");
        tx.commit();
        return result[0][0].as<std::int64_t>();
    }

private:
    Connection& conn_;

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
};

} // namespace cargo_operations
