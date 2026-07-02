#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "user_role.hpp"
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

/// Concrete CRTP repository implementation for UserRole.
/// Satisfies RepositoryBase<UserRoleRepositoryImpl<C>, UserRole> contract.
/// Uses embedded SQL constants from security_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class UserRoleRepositoryImpl {
public:
    explicit UserRoleRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const UserRole& entity) -> void {
        DbaOperationSpan span("UserRoleRepositoryImpl::save");
        auto tx = conn_.begin();
        tx.exec_params(queries::UserRoleInsert, entity.id, entity.user_id, entity.role_id);
        tx.commit();
        span.set_status_ok();
    }

    auto update(const UserRole& entity) -> void {
        DbaOperationSpan span("UserRoleRepositoryImpl::update");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::UserRoleUpdate, entity.id, entity.user_id, entity.role_id);
        if (result.affected_rows() == 0) {
            span.set_error("not found");
            throw std::runtime_error("UserRole not found: " + entity.id);
        }
        tx.commit();
        span.set_status_ok();
    }

    auto remove(const std::string& id) -> void {
        DbaOperationSpan span("UserRoleRepositoryImpl::remove");
        auto tx = conn_.begin();
        tx.exec_params(queries::UserRoleDelete, id);
        tx.commit();
        span.set_status_ok();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<UserRole> {
        DbaOperationSpan span("UserRoleRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::UserRoleSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        auto mapped = map_row(result[0]);
        span.set_status_ok();
        return mapped;
    }

    [[nodiscard]] auto find_all() -> std::vector<UserRole> {
        DbaOperationSpan span("UserRoleRepositoryImpl::find_all");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::UserRoleSelectAll);
        tx.commit();
        auto out = std::vector<UserRole>{ };
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        span.set_status_ok();
        return out;
    }

    /// Filter all entities by a domain specification (in-memory).
    template<typename Spec>
    [[nodiscard]] auto filter_by_spec(const Spec& spec) const -> std::vector<UserRole> {
        auto all = find_all();
        auto result = std::vector<UserRole>{};
        std::copy_if(all.begin(), all.end(), std::back_inserter(result),
                     [&spec](const UserRole& e) { return spec.is_satisfied_by(e); });
        return result;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> UserRole {
        return UserRole{
            .id = row[0].as<std::string>(),
            .user_id = row[1].as<boost::uuids::uuid>(),
            .role_id = row[2].as<boost::uuids::uuid>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace security
