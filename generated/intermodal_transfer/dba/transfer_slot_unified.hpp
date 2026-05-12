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
    boost::uuids::uuid id{};
    SlotReference reference{};
    boost::uuids::uuid container_id{};
    std::string transport_mode{};
    muscovite::dba::Timestamp scheduled_at{};
    std::string status{};

    /// Construct from a database row (stub — implementation in .cpp).
    // static auto from_row(const pqxx::row& row) -> TransferSlot;

    /// Try to construct; returns nullopt on missing required field.
    // static auto try_from(const pqxx::row& row) -> std::optional<TransferSlot>;
};

} // namespace intermodal_transfer
