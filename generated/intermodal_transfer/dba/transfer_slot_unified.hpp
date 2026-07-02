#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace intermodal_transfer {

/// Unified DBA struct for TransferSlot.
struct TransferSlot {
    boost::uuids::uuid id{};
    SlotReference reference{};
    boost::uuids::uuid container_id{};
    std::string transport_mode{};
    muscovite::dba::Timestamp scheduled_at{};
    std::string status{};

    /// Construct from a database row.
    static auto from_row(const pqxx::row& row) -> TransferSlot {
        return TransferSlot{
            .id = row[0].as<std::string>(),
            .reference = row[1].as<std::string>(),
            .container_id = row[2].as<std::string>(),
            .transport_mode = row[3].as<std::string>(),
            .scheduled_at = row[4].as<std::string>(),
            .status = row[5].as<std::string>(),
        };
    }

    /// Try to construct; returns nullopt on missing required field.
    static auto try_from(const pqxx::row& row) -> std::optional<TransferSlot> {
        if (row[0].is_null()) return std::nullopt;
        if (row[1].is_null()) return std::nullopt;
        if (row[2].is_null()) return std::nullopt;
        if (row[3].is_null()) return std::nullopt;
        if (row[4].is_null()) return std::nullopt;
        if (row[5].is_null()) return std::nullopt;
        return from_row(row);
    }
};

} // namespace intermodal_transfer
