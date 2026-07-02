#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "permission.hpp"
#include "security_queries.hpp"
#include <algorithm>
#include <iterator>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>

namespace security {

class DbaOperationSpan {
public:
    explicit DbaOperationSpan(std::string_view operation) : operation_{operation} {}
    auto set_status_ok() noexcept -> void {}
    auto set_error(std::string_view /*message*/) noexcept -> void {}
private:
    std::string_view operation_;
};

/// Concrete CRTP repository implementation for Permission.
/// Satisfies RepositoryBase<PermissionRepositoryImpl<C>, Permission> contract.
/// Uses embedded SQL constants from security_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class PermissionRepositoryImpl {
public:
    explicit PermissionRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const Permission& entity) -> void {
        DbaOperationSpan span("PermissionRepositoryImpl::save");
        auto tx = conn_.begin();
        tx.exec_params(queries::PermissionInsert, entity.id, entity.name, entity.resource, entity.action);
        tx.commit();
        span.set_status_ok();
    }

    auto update(const Permission& entity) -> void {
        DbaOperationSpan span("PermissionRepositoryImpl::update");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::PermissionUpdate, entity.id, entity.name, entity.resource, entity.action);
        if (result.affected_rows() == 0) {
            span.set_error("not found");
            throw std::runtime_error("Permission not found: " + entity.id);
        }
        tx.commit();
        span.set_status_ok();
    }

    auto remove(const std::string& id) -> void {
        DbaOperationSpan span("PermissionRepositoryImpl::remove");
        auto tx = conn_.begin();
        tx.exec_params(queries::PermissionDelete, id);
        tx.commit();
        span.set_status_ok();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<Permission> {
        DbaOperationSpan span("PermissionRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::PermissionSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        auto mapped = map_row(result[0]);
        span.set_status_ok();
        return mapped;
    }

    [[nodiscard]] auto find_all() -> std::vector<Permission> {
        DbaOperationSpan span("PermissionRepositoryImpl::find_all");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::PermissionSelectAll);
        tx.commit();
        auto out = std::vector<Permission>{ };
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        span.set_status_ok();
        return out;
    }

    /// Filter all entities by a domain specification (in-memory).
    template<typename Spec>
    [[nodiscard]] auto filter_by_spec(const Spec& spec) const -> std::vector<Permission> {
        auto all = find_all();
        auto result = std::vector<Permission>{};
        std::copy_if(all.begin(), all.end(), std::back_inserter(result),
                     [&spec](const Permission& e) { return spec.is_satisfied_by(e); });
        return result;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> Permission {
        return Permission{
            .id = row[0].as<std::string>(),
            .name = row[1].as<std::string>(),
            .resource = row[2].as<std::string>(),
            .action = row[3].as<std::string>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace security
