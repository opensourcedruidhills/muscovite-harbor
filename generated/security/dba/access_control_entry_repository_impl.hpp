#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "access_control_entry.hpp"
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

/// Concrete CRTP repository implementation for AccessControlEntry.
/// Satisfies RepositoryBase<AccessControlEntryRepositoryImpl<C>, AccessControlEntry> contract.
/// Uses embedded SQL constants from security_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class AccessControlEntryRepositoryImpl {
public:
    explicit AccessControlEntryRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const AccessControlEntry& entity) -> void {
        DbaOperationSpan span("AccessControlEntryRepositoryImpl::save");
        auto tx = conn_.begin();
        tx.exec_params(queries::AccessControlEntryInsert, entity.id, entity.principal, entity.resource, entity.permission, entity.effect);
        tx.commit();
        span.set_status_ok();
    }

    auto update(const AccessControlEntry& entity) -> void {
        DbaOperationSpan span("AccessControlEntryRepositoryImpl::update");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::AccessControlEntryUpdate, entity.id, entity.principal, entity.resource, entity.permission, entity.effect);
        if (result.affected_rows() == 0) {
            span.set_error("not found");
            throw std::runtime_error("AccessControlEntry not found: " + entity.id);
        }
        tx.commit();
        span.set_status_ok();
    }

    auto remove(const std::string& id) -> void {
        DbaOperationSpan span("AccessControlEntryRepositoryImpl::remove");
        auto tx = conn_.begin();
        tx.exec_params(queries::AccessControlEntryDelete, id);
        tx.commit();
        span.set_status_ok();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<AccessControlEntry> {
        DbaOperationSpan span("AccessControlEntryRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::AccessControlEntrySelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        auto mapped = map_row(result[0]);
        span.set_status_ok();
        return mapped;
    }

    [[nodiscard]] auto find_all() -> std::vector<AccessControlEntry> {
        DbaOperationSpan span("AccessControlEntryRepositoryImpl::find_all");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::AccessControlEntrySelectAll);
        tx.commit();
        auto out = std::vector<AccessControlEntry>{ };
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        span.set_status_ok();
        return out;
    }

    /// Filter all entities by a domain specification (in-memory).
    template<typename Spec>
    [[nodiscard]] auto filter_by_spec(const Spec& spec) const -> std::vector<AccessControlEntry> {
        auto all = find_all();
        auto result = std::vector<AccessControlEntry>{};
        std::copy_if(all.begin(), all.end(), std::back_inserter(result),
                     [&spec](const AccessControlEntry& e) { return spec.is_satisfied_by(e); });
        return result;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> AccessControlEntry {
        return AccessControlEntry{
            .id = row[0].as<std::string>(),
            .principal = row[1].as<std::string>(),
            .resource = row[2].as<std::string>(),
            .permission = row[3].as<std::string>(),
            .effect = row[4].as<std::string>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace security
