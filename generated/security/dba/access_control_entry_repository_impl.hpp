#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "access_control_entry.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace security {

/// Concrete CRTP repository implementation for AccessControlEntry.
/// Satisfies RepositoryBase<AccessControlEntryRepositoryImpl<C>, AccessControlEntry> contract.
/// Uses parameterised SQL (pqxx) — no stored procedures (ADR 20260120).
template<typename Connection>
class AccessControlEntryRepositoryImpl {
public:
    explicit AccessControlEntryRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto build_select_by_id_query() const -> std::string {
        return "SELECT id, principal, resource, permission, effect FROM security.access_control_entry WHERE id = $1";
    }

    [[nodiscard]] auto build_insert_query() const -> std::string {
        return "INSERT INTO security.access_control_entry (id, principal, resource, permission, effect) VALUES ($1, $2, $3, $4, $5) RETURNING id";
    }

    [[nodiscard]] auto build_update_query() const -> std::string {
        return "UPDATE security.access_control_entry SET principal = $2, resource = $3, permission = $4, effect = $5 WHERE id = $1";
    }

    [[nodiscard]] auto build_delete_query() const -> std::string {
        return "DELETE FROM security.access_control_entry WHERE id = $1";
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

    auto save(const AccessControlEntry& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_insert_query(), entity.id, entity.principal, entity.resource, entity.permission, entity.effect);
        tx.commit();
    }

    auto update(const AccessControlEntry& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_update_query(), entity.id, entity.principal, entity.resource, entity.permission, entity.effect);
        if (result.affected_rows() == 0) {
            throw std::runtime_error("AccessControlEntry not found: " + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_delete_query(), id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<AccessControlEntry> {
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
