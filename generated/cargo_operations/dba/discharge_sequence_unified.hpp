#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace cargo_operations {

/// Unified DBA struct for DischargeSequence.
struct DischargeSequence {
    boost::uuids::uuid id{};
    boost::uuids::uuid load_plan_id{};
    boost::uuids::uuid container_id{};
    std::int32_t sequence_order{};
    boost::uuids::uuid crane_id{};

    /// Construct from a database row.
    static auto from_row(const pqxx::row& row) -> DischargeSequence {
        return DischargeSequence{
            .id = row[0].as<std::string>(),
            .load_plan_id = row[1].as<std::string>(),
            .container_id = row[2].as<std::string>(),
            .sequence_order = row[3].as<std::string>(),
            .crane_id = row[4].as<std::string>(),
        };
    }

    /// Try to construct; returns nullopt on missing required field.
    static auto try_from(const pqxx::row& row) -> std::optional<DischargeSequence> {
        if (row[0].is_null()) return std::nullopt;
        if (row[1].is_null()) return std::nullopt;
        if (row[2].is_null()) return std::nullopt;
        if (row[3].is_null()) return std::nullopt;
        return from_row(row);
    }
};

} // namespace cargo_operations
