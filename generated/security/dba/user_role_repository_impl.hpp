#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "user_role.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace security {

/// Concrete CRTP repository implementation for UserRole.
/// Satisfies RepositoryBase<UserRoleRepositoryImpl<C>, UserRole> contract.
/// Uses parameterised SQL (pqxx) — no stored procedures (ADR 20260120).
template<typename Connection>
class UserRoleRepositoryImpl {
public:
    explicit UserRoleRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto build_select_by_id_query() const -> std::string {
        return "SELECT id, user_id, role_id FROM security.user_role WHERE id = $1";
    }

    [[nodiscard]] auto build_insert_query() const -> std::string {
        return "INSERT INTO security.user_role (id, user_id, role_id) VALUES ($1, $2, $3) RETURNING id";
    }

    [[nodiscard]] auto build_update_query() const -> std::string {
        return "UPDATE security.user_role SET user_id = $2, role_id = $3 WHERE id = $1";
    }

    [[nodiscard]] auto build_delete_query() const -> std::string {
        return "DELETE FROM security.user_role WHERE id = $1";
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> UserRole {
        return UserRole{
            .id = row[0].as<std::string>(),
            .user_id = row[1].as<std::string>(),
            .role_id = row[2].as<std::string>(),
        };
    }

    auto save(const UserRole& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_insert_query(), entity.id, entity.user_id, entity.role_id);
        tx.commit();
    }

    auto update(const UserRole& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_update_query(), entity.id, entity.user_id, entity.role_id);
        if (result.affected_rows() == 0) {
            throw std::runtime_error("UserRole not found: " + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_delete_query(), id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<UserRole> {
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
