#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "container_command_repository.hpp"
#include "cargo_operations_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>

namespace cargo_operations {

class DbaOperationSpan {
public:
    explicit DbaOperationSpan(std::string_view operation) : operation_{operation} {}
    auto set_status_ok() noexcept -> void {}
    auto set_error(std::string_view /*message*/) noexcept -> void {}
private:
    std::string_view operation_;
};

/// pqxx-based command repository implementation for Container aggregate.
/// Uses embedded SQL constants from cargo_operations_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class ContainerCommandRepositoryImpl : public ContainerCommandRepository {
public:
    explicit ContainerCommandRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const Container& entity) -> void override {
        DbaOperationSpan span("ContainerCommandRepositoryImpl::save");
        auto tx = conn_.begin();
        tx.exec_params(queries::ContainerUpsert,
            entity.id, entity.container_number, entity.size_category, entity.hazmat_class, entity.voyage_id, entity.yard_slot_id, entity.status);
        tx.commit();
        span.set_status_ok();
    }

    auto update(const Container& entity) -> void override {
        DbaOperationSpan span("ContainerCommandRepositoryImpl::update");
        auto tx = conn_.begin();
        tx.exec_params(queries::ContainerUpdate,
            entity.id, entity.container_number, entity.size_category, entity.hazmat_class, entity.voyage_id, entity.yard_slot_id, entity.status);
        tx.commit();
        span.set_status_ok();
    }

    auto remove(const Container::Id& id) -> void override {
        DbaOperationSpan span("ContainerCommandRepositoryImpl::remove");
        auto tx = conn_.begin();
        tx.exec_params(queries::ContainerDelete, id);
        tx.commit();
        span.set_status_ok();
    }

    [[nodiscard]] auto find_by_id(const Container::Id& id) -> std::optional<Container> override {
        DbaOperationSpan span("ContainerCommandRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::ContainerSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        const auto& row = result[0];
        auto entity = Container{
            .id = row[0].as<std::string>(),
            .container_number = row[1].as<std::string>(),
            .size_category = row[2].as<std::string>(),
            .hazmat_class = row[3].as<std::string>(),
            .voyage_id = row[4].as<boost::uuids::uuid>(),
            .yard_slot_id = row[5].as<boost::uuids::uuid>(),
            .status = row[6].as<std::string>(),
        };
        span.set_status_ok();
        return entity;
    }

private:
    Connection& conn_;
;

} // namespace cargo_operations
