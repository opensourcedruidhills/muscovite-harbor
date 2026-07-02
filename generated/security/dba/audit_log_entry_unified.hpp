#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace security {

/// Unified DBA struct for AuditLogEntry.
struct AuditLogEntry {
    boost::uuids::uuid id{};
    muscovite::dba::Timestamp timestamp{};
    std::string actor{};
    std::string action{};
    std::string resource{};
    std::string details{};

    /// Construct from a database row.
    static auto from_row(const pqxx::row& row) -> AuditLogEntry {
        return AuditLogEntry{
            .id = row[0].as<std::string>(),
            .timestamp = row[1].as<std::string>(),
            .actor = row[2].as<std::string>(),
            .action = row[3].as<std::string>(),
            .resource = row[4].as<std::string>(),
            .details = row[5].as<std::string>(),
        };
    }

    /// Try to construct; returns nullopt on missing required field.
    static auto try_from(const pqxx::row& row) -> std::optional<AuditLogEntry> {
        if (row[0].is_null()) return std::nullopt;
        if (row[1].is_null()) return std::nullopt;
        if (row[2].is_null()) return std::nullopt;
        if (row[3].is_null()) return std::nullopt;
        if (row[4].is_null()) return std::nullopt;
        return from_row(row);
    }
};

} // namespace security
