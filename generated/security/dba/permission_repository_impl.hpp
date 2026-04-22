#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "permission.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace security {

/// Concrete CRTP repository implementation for Permission.
/// Satisfies RepositoryBase<PermissionRepositoryImpl<C>, Permission> contract.
/// Uses parameterised SQL (pqxx) — no stored procedures (ADR 20260120).
template<typename Connection>
class PermissionRepositoryImpl {
public:
    explicit PermissionRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto build_select_by_id_query() const -> std::string {
        return "SELECT id, name, resource, action FROM security.permission WHERE id = $1";
    }

    [[nodiscard]] auto build_insert_query() const -> std::string {
        return "INSERT INTO security.permission (id, name, resource, action) VALUES ($1, $2, $3, $4) RETURNING id";
    }

    [[nodiscard]] auto build_update_query() const -> std::string {
        return "UPDATE security.permission SET name = $2, resource = $3, action = $4 WHERE id = $1";
    }

    [[nodiscard]] auto build_delete_query() const -> std::string {
        return "DELETE FROM security.permission WHERE id = $1";
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> Permission {
        return Permission{
            .id = row[0].as<std::string>(),
            .name = row[1].as<std::string>(),
            .resource = row[2].as<std::string>(),
            .action = row[3].as<std::string>(),
        };
    }

    auto save(const Permission& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_insert_query(), entity.id, entity.name, entity.resource, entity.action);
        tx.commit();
    }

    auto update(const Permission& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_update_query(), entity.id, entity.name, entity.resource, entity.action);
        if (result.affected_rows() == 0) {
            throw std::runtime_error("Permission not found: " + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_delete_query(), id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<Permission> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_select_by_id_query(), id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

private:
    Connection& conn_;
};

} // namespace security
