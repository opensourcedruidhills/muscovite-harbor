#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace cargo_operations {

/// Unified DBA struct for Container.
struct Container {
    boost::uuids::uuid id{};
    ContainerNumber container_number{};
    std::string size_category{};
    std::string hazmat_class{};
    boost::uuids::uuid voyage_id{};
    boost::uuids::uuid yard_slot_id{};
    std::string status{};

    /// Construct from a database row.
    static auto from_row(const pqxx::row& row) -> Container {
        return Container{
            .id = row[0].as<std::string>(),
            .container_number = row[1].as<std::string>(),
            .size_category = row[2].as<std::string>(),
            .hazmat_class = row[3].as<std::string>(),
            .voyage_id = row[4].as<std::string>(),
            .yard_slot_id = row[5].as<std::string>(),
            .status = row[6].as<std::string>(),
        };
    }

    /// Try to construct; returns nullopt on missing required field.
    static auto try_from(const pqxx::row& row) -> std::optional<Container> {
        if (row[0].is_null()) return std::nullopt;
        if (row[1].is_null()) return std::nullopt;
        if (row[2].is_null()) return std::nullopt;
        if (row[4].is_null()) return std::nullopt;
        if (row[6].is_null()) return std::nullopt;
        return from_row(row);
    }
};

} // namespace cargo_operations
