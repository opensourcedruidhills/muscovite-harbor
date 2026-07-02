#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "container.hpp"
#include "cargo_operations_queries.hpp"
#include <algorithm>
#include <iterator>
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

/// Concrete CRTP repository implementation for Container.
/// Satisfies RepositoryBase<ContainerRepositoryImpl<C>, Container> contract.
/// Uses embedded SQL constants from cargo_operations_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class ContainerRepositoryImpl {
public:
    explicit ContainerRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const Container& entity) -> void {
        DbaOperationSpan span("ContainerRepositoryImpl::save");
        auto tx = conn_.begin();
        tx.exec_params(queries::ContainerInsert, entity.id, entity.container_number, entity.size_category, entity.hazmat_class, entity.voyage_id, entity.yard_slot_id, entity.status);
        tx.commit();
        span.set_status_ok();
    }

    auto update(const Container& entity) -> void {
        DbaOperationSpan span("ContainerRepositoryImpl::update");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::ContainerUpdate, entity.id, entity.container_number, entity.size_category, entity.hazmat_class, entity.voyage_id, entity.yard_slot_id, entity.status);
        if (result.affected_rows() == 0) {
            span.set_error("not found");
            throw std::runtime_error("Container not found: " + entity.id);
        }
        tx.commit();
        span.set_status_ok();
    }

    auto remove(const std::string& id) -> void {
        DbaOperationSpan span("ContainerRepositoryImpl::remove");
        auto tx = conn_.begin();
        tx.exec_params(queries::ContainerDelete, id);
        tx.commit();
        span.set_status_ok();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<Container> {
        DbaOperationSpan span("ContainerRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::ContainerSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        auto mapped = map_row(result[0]);
        span.set_status_ok();
        return mapped;
    }

    [[nodiscard]] auto find_all() -> std::vector<Container> {
        DbaOperationSpan span("ContainerRepositoryImpl::find_all");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::ContainerSelectAll);
        tx.commit();
        auto out = std::vector<Container>{ };
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        span.set_status_ok();
        return out;
    }

    /// Filter all entities by a domain specification (in-memory).
    template<typename Spec>
    [[nodiscard]] auto filter_by_spec(const Spec& spec) const -> std::vector<Container> {
        auto all = find_all();
        auto result = std::vector<Container>{};
        std::copy_if(all.begin(), all.end(), std::back_inserter(result),
                     [&spec](const Container& e) { return spec.is_satisfied_by(e); });
        return result;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> Container {
        return Container{
            .id = row[0].as<std::string>(),
            .container_number = row[1].as<std::string>(),
            .size_category = row[2].as<std::string>(),
            .hazmat_class = row[3].as<std::string>(),
            .voyage_id = row[4].as<boost::uuids::uuid>(),
            .yard_slot_id = row[5].as<boost::uuids::uuid>(),
            .status = row[6].as<std::string>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace cargo_operations
