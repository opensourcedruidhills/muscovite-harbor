#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "permission.hpp"
#include "security_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace security {

/// Concrete CRTP repository implementation for Permission.
/// Satisfies RepositoryBase<PermissionRepositoryImpl<C>, Permission> contract.
/// Uses embedded SQL constants from security_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class PermissionRepositoryImpl {
public:
    explicit PermissionRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const Permission& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::PermissionInsert, entity.id, entity.name, entity.resource, entity.action);
        tx.commit();
    }

    auto update(const Permission& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::PermissionUpdate, entity.id, entity.name, entity.resource, entity.action);
        if (result.affected_rows() == 0) {
            throw std::runtime_error(Permission not found:  + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::PermissionDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<Permission> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::PermissionSelectById, id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<Permission> {
        auto tx = conn_.begin();
        auto result = tx.exec(queries::PermissionSelectAll);
        tx.commit();
        auto out = std::vector<Permission>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
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
