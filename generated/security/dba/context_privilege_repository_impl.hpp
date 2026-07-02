#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "context_privilege.hpp"
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

/// Concrete CRTP repository implementation for ContextPrivilege.
/// Satisfies RepositoryBase<ContextPrivilegeRepositoryImpl<C>, ContextPrivilege> contract.
/// Uses embedded SQL constants from security_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class ContextPrivilegeRepositoryImpl {
public:
    explicit ContextPrivilegeRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const ContextPrivilege& entity) -> void {
        DbaOperationSpan span("ContextPrivilegeRepositoryImpl::save");
        auto tx = conn_.begin();
        tx.exec_params(queries::ContextPrivilegeInsert, entity.id, entity.context_name, entity.group_id, entity.privilege);
        tx.commit();
        span.set_status_ok();
    }

    auto update(const ContextPrivilege& entity) -> void {
        DbaOperationSpan span("ContextPrivilegeRepositoryImpl::update");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::ContextPrivilegeUpdate, entity.id, entity.context_name, entity.group_id, entity.privilege);
        if (result.affected_rows() == 0) {
            span.set_error("not found");
            throw std::runtime_error("ContextPrivilege not found: " + entity.id);
        }
        tx.commit();
        span.set_status_ok();
    }

    auto remove(const std::string& id) -> void {
        DbaOperationSpan span("ContextPrivilegeRepositoryImpl::remove");
        auto tx = conn_.begin();
        tx.exec_params(queries::ContextPrivilegeDelete, id);
        tx.commit();
        span.set_status_ok();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<ContextPrivilege> {
        DbaOperationSpan span("ContextPrivilegeRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::ContextPrivilegeSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        auto mapped = map_row(result[0]);
        span.set_status_ok();
        return mapped;
    }

    [[nodiscard]] auto find_all() -> std::vector<ContextPrivilege> {
        DbaOperationSpan span("ContextPrivilegeRepositoryImpl::find_all");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::ContextPrivilegeSelectAll);
        tx.commit();
        auto out = std::vector<ContextPrivilege>{ };
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        span.set_status_ok();
        return out;
    }

    /// Filter all entities by a domain specification (in-memory).
    template<typename Spec>
    [[nodiscard]] auto filter_by_spec(const Spec& spec) const -> std::vector<ContextPrivilege> {
        auto all = find_all();
        auto result = std::vector<ContextPrivilege>{};
        std::copy_if(all.begin(), all.end(), std::back_inserter(result),
                     [&spec](const ContextPrivilege& e) { return spec.is_satisfied_by(e); });
        return result;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> ContextPrivilege {
        return ContextPrivilege{
            .id = row[0].as<std::string>(),
            .context_name = row[1].as<std::string>(),
            .group_id = row[2].as<boost::uuids::uuid>(),
            .privilege = row[3].as<std::string>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace security
