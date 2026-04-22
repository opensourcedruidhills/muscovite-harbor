#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "container_command_repository.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace cargo_operations {

/// pqxx-based command repository implementation for Container aggregate.
/// Uses direct parameterised SQL — no stored procedures (ADR 20260120).
template<typename Connection>
class ContainerCommandRepositoryImpl : public ContainerCommandRepository {
public:
    explicit ContainerCommandRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const Container& entity) -> void override {
        auto tx = conn_.begin();
        tx.exec_params("INSERT INTO cargo_operations.container (id, id, container_number, size_category, hazmat_class, voyage_id, yard_slot_id, status) VALUES ($1, $2, $3, $4, $5, $6, $7, $8) ON CONFLICT (id) DO UPDATE SET id = $2, container_number = $3, size_category = $4, hazmat_class = $5, voyage_id = $6, yard_slot_id = $7, status = $8",
            entity.id, entity.id, entity.container_number, entity.size_category, entity.hazmat_class, entity.voyage_id, entity.yard_slot_id, entity.status);
        tx.commit();
    }

    auto remove(const Container::Id& id) -> void override {
        auto tx = conn_.begin();
        tx.exec_params("DELETE FROM cargo_operations.container WHERE id = $1", id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const Container::Id& id) -> std::optional<Container> override {
        auto tx = conn_.begin();
        auto result = tx.exec_params("SELECT id, id, container_number, size_category, hazmat_class, voyage_id, yard_slot_id, status FROM cargo_operations.container WHERE id = $1", id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        const auto& row = result[0];
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
};

} // namespace cargo_operations
