#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "user.hpp"
#include "security_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace security {

/// Concrete CRTP repository implementation for User.
/// Satisfies RepositoryBase<UserRepositoryImpl<C>, User> contract.
/// Uses embedded SQL constants from security_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class UserRepositoryImpl {
public:
    explicit UserRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const User& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::UserInsert, entity.id, entity.username, entity.email, entity.password_hash, entity.is_active);
        tx.commit();
    }

    auto update(const User& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::UserUpdate, entity.id, entity.username, entity.email, entity.password_hash, entity.is_active);
        if (result.affected_rows() == 0) {
            throw std::runtime_error(User not found:  + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::UserDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<User> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::UserSelectById, id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<User> {
        auto tx = conn_.begin();
        auto result = tx.exec(queries::UserSelectAll);
        tx.commit();
        auto out = std::vector<User>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
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

private:
    Connection& conn_;
;

} // namespace security
