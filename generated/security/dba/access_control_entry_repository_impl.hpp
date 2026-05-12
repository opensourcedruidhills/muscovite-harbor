#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "access_control_entry.hpp"
#include "security_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace security {

/// Concrete CRTP repository implementation for AccessControlEntry.
/// Satisfies RepositoryBase<AccessControlEntryRepositoryImpl<C>, AccessControlEntry> contract.
/// Uses embedded SQL constants from security_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class AccessControlEntryRepositoryImpl {
public:
    explicit AccessControlEntryRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const AccessControlEntry& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::AccessControlEntryInsert, entity.id, entity.principal, entity.resource, entity.permission, entity.effect);
        tx.commit();
    }

    auto update(const AccessControlEntry& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::AccessControlEntryUpdate, entity.id, entity.principal, entity.resource, entity.permission, entity.effect);
        if (result.affected_rows() == 0) {
            throw std::runtime_error(AccessControlEntry not found:  + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::AccessControlEntryDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<AccessControlEntry> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::AccessControlEntrySelectById, id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<AccessControlEntry> {
        auto tx = conn_.begin();
        auto result = tx.exec(queries::AccessControlEntrySelectAll);
        tx.commit();
        auto out = std::vector<AccessControlEntry>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
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
