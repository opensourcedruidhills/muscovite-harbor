#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "user.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace security {

/// Concrete CRTP repository implementation for User.
/// Satisfies RepositoryBase<UserRepositoryImpl<C>, User> contract.
/// Uses parameterised SQL (pqxx) — no stored procedures (ADR 20260120).
template<typename Connection>
class UserRepositoryImpl {
public:
    explicit UserRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto build_select_by_id_query() const -> std::string {
        return "SELECT id, username, email, password_hash, is_active FROM security.user WHERE id = $1";
    }

    [[nodiscard]] auto build_insert_query() const -> std::string {
        return "INSERT INTO security.user (id, username, email, password_hash, is_active) VALUES ($1, $2, $3, $4, $5) RETURNING id";
    }

    [[nodiscard]] auto build_update_query() const -> std::string {
        return "UPDATE security.user SET username = $2, email = $3, password_hash = $4, is_active = $5 WHERE id = $1";
    }

    [[nodiscard]] auto build_delete_query() const -> std::string {
        return "DELETE FROM security.user WHERE id = $1";
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> User {
        return User{
            .id = row[0].as<std::string>(),
            .username = row[1].as<std::string>(),
            .email = row[2].as<std::string>(),
            .password_hash = row[3].as<std::string>(),
            .is_active = row[4].as<std::string>(),
        };
    }

    auto save(const User& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_insert_query(), entity.id, entity.username, entity.email, entity.password_hash, entity.is_active);
        tx.commit();
    }

    auto update(const User& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_update_query(), entity.id, entity.username, entity.email, entity.password_hash, entity.is_active);
        if (result.affected_rows() == 0) {
            throw std::runtime_error("User not found: " + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_delete_query(), id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<User> {
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
