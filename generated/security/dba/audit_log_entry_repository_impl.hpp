#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "audit_log_entry.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace security {

/// Concrete CRTP repository implementation for AuditLogEntry.
/// Satisfies RepositoryBase<AuditLogEntryRepositoryImpl<C>, AuditLogEntry> contract.
/// Uses parameterised SQL (pqxx) — no stored procedures (ADR 20260120).
template<typename Connection>
class AuditLogEntryRepositoryImpl {
public:
    explicit AuditLogEntryRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto build_select_by_id_query() const -> std::string {
        return "SELECT id, timestamp, actor, action, resource, details FROM security.audit_log_entry WHERE id = $1";
    }

    [[nodiscard]] auto build_insert_query() const -> std::string {
        return "INSERT INTO security.audit_log_entry (id, timestamp, actor, action, resource, details) VALUES ($1, $2, $3, $4, $5, $6) RETURNING id";
    }

    [[nodiscard]] auto build_update_query() const -> std::string {
        return "UPDATE security.audit_log_entry SET timestamp = $2, actor = $3, action = $4, resource = $5, details = $6 WHERE id = $1";
    }

    [[nodiscard]] auto build_delete_query() const -> std::string {
        return "DELETE FROM security.audit_log_entry WHERE id = $1";
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> AuditLogEntry {
        return AuditLogEntry{
            .id = row[0].as<std::string>(),
            .timestamp = row[1].as<std::string>(),
            .actor = row[2].as<std::string>(),
            .action = row[3].as<std::string>(),
            .resource = row[4].as<std::string>(),
            .details = row[5].as<std::string>(),
        };
    }

    auto save(const AuditLogEntry& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_insert_query(), entity.id, entity.timestamp, entity.actor, entity.action, entity.resource, entity.details);
        tx.commit();
    }

    auto update(const AuditLogEntry& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_update_query(), entity.id, entity.timestamp, entity.actor, entity.action, entity.resource, entity.details);
        if (result.affected_rows() == 0) {
            throw std::runtime_error("AuditLogEntry not found: " + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_delete_query(), id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<AuditLogEntry> {
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
