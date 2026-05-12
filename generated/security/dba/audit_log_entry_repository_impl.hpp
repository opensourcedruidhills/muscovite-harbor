#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "audit_log_entry.hpp"
#include "security_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace security {

/// Concrete CRTP repository implementation for AuditLogEntry.
/// Satisfies RepositoryBase<AuditLogEntryRepositoryImpl<C>, AuditLogEntry> contract.
/// Uses embedded SQL constants from security_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class AuditLogEntryRepositoryImpl {
public:
    explicit AuditLogEntryRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const AuditLogEntry& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::AuditLogEntryInsert, entity.id, entity.timestamp, entity.actor, entity.action, entity.resource, entity.details);
        tx.commit();
    }

    auto update(const AuditLogEntry& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::AuditLogEntryUpdate, entity.id, entity.timestamp, entity.actor, entity.action, entity.resource, entity.details);
        if (result.affected_rows() == 0) {
            throw std::runtime_error(AuditLogEntry not found:  + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::AuditLogEntryDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<AuditLogEntry> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::AuditLogEntrySelectById, id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<AuditLogEntry> {
        auto tx = conn_.begin();
        auto result = tx.exec(queries::AuditLogEntrySelectAll);
        tx.commit();
        auto out = std::vector<AuditLogEntry>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
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

private:
    Connection& conn_;
;

} // namespace security
