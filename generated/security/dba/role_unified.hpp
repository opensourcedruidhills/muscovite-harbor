#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace security {

/// Unified DBA struct for Role.
struct Role {
    boost::uuids::uuid id{};
    std::string name{};
    std::string description{};
    std::string permissions{};

    /// Construct from a database row.
    static auto from_row(const pqxx::row& row) -> Role {
        return Role{
            .id = row[0].as<std::string>(),
            .name = row[1].as<std::string>(),
            .description = row[2].as<std::string>(),
            .permissions = row[3].as<std::string>(),
        };
    }

    /// Try to construct; returns nullopt on missing required field.
    static auto try_from(const pqxx::row& row) -> std::optional<Role> {
        if (row[0].is_null()) return std::nullopt;
        if (row[1].is_null()) return std::nullopt;
        if (row[3].is_null()) return std::nullopt;
        return from_row(row);
    }
};

} // namespace security
