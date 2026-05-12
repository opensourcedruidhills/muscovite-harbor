#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "user_role.hpp"
#include "security_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace security {

/// Concrete CRTP repository implementation for UserRole.
/// Satisfies RepositoryBase<UserRoleRepositoryImpl<C>, UserRole> contract.
/// Uses embedded SQL constants from security_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class UserRoleRepositoryImpl {
public:
    explicit UserRoleRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const UserRole& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::UserRoleInsert, entity.id, entity.user_id, entity.role_id);
        tx.commit();
    }

    auto update(const UserRole& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::UserRoleUpdate, entity.id, entity.user_id, entity.role_id);
        if (result.affected_rows() == 0) {
            throw std::runtime_error(UserRole not found:  + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::UserRoleDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<UserRole> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::UserRoleSelectById, id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<UserRole> {
        auto tx = conn_.begin();
        auto result = tx.exec(queries::UserRoleSelectAll);
        tx.commit();
        auto out = std::vector<UserRole>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> UserRole {
        return UserRole{
            .id = row[0].as<std::string>(),
            .user_id = row[1].as<std::string>(),
            .role_id = row[2].as<std::string>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace security
