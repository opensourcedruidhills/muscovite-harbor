#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace security {

/// Unified DBA struct for ContextPrivilege.
struct ContextPrivilege {
    boost::uuids::uuid id{};
    std::string context_name{};
    boost::uuids::uuid group_id{};
    std::string privilege{};

    /// Construct from a database row.
    static auto from_row(const pqxx::row& row) -> ContextPrivilege {
        return ContextPrivilege{
            .id = row[0].as<std::string>(),
            .context_name = row[1].as<std::string>(),
            .group_id = row[2].as<std::string>(),
            .privilege = row[3].as<std::string>(),
        };
    }

    /// Try to construct; returns nullopt on missing required field.
    static auto try_from(const pqxx::row& row) -> std::optional<ContextPrivilege> {
        if (row[0].is_null()) return std::nullopt;
        if (row[1].is_null()) return std::nullopt;
        if (row[2].is_null()) return std::nullopt;
        if (row[3].is_null()) return std::nullopt;
        return from_row(row);
    }
};

} // namespace security
