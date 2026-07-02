#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "user.hpp"
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

/// Concrete CRTP repository implementation for User.
/// Satisfies RepositoryBase<UserRepositoryImpl<C>, User> contract.
/// Uses embedded SQL constants from security_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class UserRepositoryImpl {
public:
    explicit UserRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const User& entity) -> void {
        DbaOperationSpan span("UserRepositoryImpl::save");
        auto tx = conn_.begin();
        tx.exec_params(queries::UserInsert, entity.id, entity.username, entity.email, entity.password_hash, entity.is_active);
        tx.commit();
        span.set_status_ok();
    }

    auto update(const User& entity) -> void {
        DbaOperationSpan span("UserRepositoryImpl::update");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::UserUpdate, entity.id, entity.username, entity.email, entity.password_hash, entity.is_active);
        if (result.affected_rows() == 0) {
            span.set_error("not found");
            throw std::runtime_error("User not found: " + entity.id);
        }
        tx.commit();
        span.set_status_ok();
    }

    auto remove(const std::string& id) -> void {
        DbaOperationSpan span("UserRepositoryImpl::remove");
        auto tx = conn_.begin();
        tx.exec_params(queries::UserDelete, id);
        tx.commit();
        span.set_status_ok();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<User> {
        DbaOperationSpan span("UserRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::UserSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        auto mapped = map_row(result[0]);
        span.set_status_ok();
        return mapped;
    }

    [[nodiscard]] auto find_all() -> std::vector<User> {
        DbaOperationSpan span("UserRepositoryImpl::find_all");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::UserSelectAll);
        tx.commit();
        auto out = std::vector<User>{ };
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        span.set_status_ok();
        return out;
    }

    /// Filter all entities by a domain specification (in-memory).
    template<typename Spec>
    [[nodiscard]] auto filter_by_spec(const Spec& spec) const -> std::vector<User> {
        auto all = find_all();
        auto result = std::vector<User>{};
        std::copy_if(all.begin(), all.end(), std::back_inserter(result),
                     [&spec](const User& e) { return spec.is_satisfied_by(e); });
        return result;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> User {
        return User{
            .id = row[0].as<std::string>(),
            .username = row[1].as<std::string>(),
            .email = row[2].as<std::string>(),
            .password_hash = row[3].as<std::string>(),
            .is_active = row[4].as<bool>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace security
