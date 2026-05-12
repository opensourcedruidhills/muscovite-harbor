#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "role.hpp"
#include "security_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace security {

/// Concrete CRTP repository implementation for Role.
/// Satisfies RepositoryBase<RoleRepositoryImpl<C>, Role> contract.
/// Uses embedded SQL constants from security_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class RoleRepositoryImpl {
public:
    explicit RoleRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const Role& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::RoleInsert, entity.id, entity.name, entity.description, entity.permissions);
        tx.commit();
    }

    auto update(const Role& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::RoleUpdate, entity.id, entity.name, entity.description, entity.permissions);
        if (result.affected_rows() == 0) {
            throw std::runtime_error(Role not found:  + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::RoleDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<Role> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::RoleSelectById, id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<Role> {
        auto tx = conn_.begin();
        auto result = tx.exec(queries::RoleSelectAll);
        tx.commit();
        auto out = std::vector<Role>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> Role {
        return Role{
            .id = row[0].as<std::string>(),
            .name = row[1].as<std::string>(),
            .description = row[2].as<std::string>(),
            .permissions = row[3].as<std::string>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace security
