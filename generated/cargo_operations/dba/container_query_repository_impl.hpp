#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "container_query_repository.hpp"
#include "cargo_operations_queries.hpp"
#include <cstdint>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

namespace cargo_operations {

class DbaOperationSpan {
public:
    explicit DbaOperationSpan(std::string_view operation) : operation_{operation} {}
    auto set_status_ok() noexcept -> void {}
    auto set_error(std::string_view /*message*/) noexcept -> void {}
private:
    std::string_view operation_;
};

/// pqxx-based query repository implementation for Container aggregate.
/// Uses embedded SQL constants from cargo_operations_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class ContainerQueryRepositoryImpl : public ContainerQueryRepository {
public:
    explicit ContainerQueryRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto find_by_id(const Container::Id& id) -> std::optional<Container> override {
        DbaOperationSpan span("ContainerQueryRepositoryImpl::find_by_id");
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

    [[nodiscard]] auto find_all() -> std::vector<Container> override {
        DbaOperationSpan span("ContainerQueryRepositoryImpl::find_all");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::ContainerSelectAll);
        tx.commit();
        auto out = std::vector<Container>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        span.set_status_ok();
        return out;
    }

    [[nodiscard]] auto count() -> std::int64_t override {
        DbaOperationSpan span("ContainerQueryRepositoryImpl::count");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::ContainerCount);
        tx.commit();
        auto total = result[0][0].as<std::int64_t>();
        span.set_status_ok();
        return total;
    }

private:
    Connection& conn_;

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> Container {
        return Container{
            .id = row[0].as<std::string>(),
            .id = row[1].as<boost::uuids::uuid>(),
            .container_number = row[2].as<std::string>(),
            .size_category = row[3].as<std::string>(),
            .hazmat_class = row[4].as<std::string>(),
            .voyage_id = row[5].as<boost::uuids::uuid>(),
            .yard_slot_id = row[6].as<boost::uuids::uuid>(),
            .status = row[7].as<std::string>(),
        };
    }
;

} // namespace cargo_operations
