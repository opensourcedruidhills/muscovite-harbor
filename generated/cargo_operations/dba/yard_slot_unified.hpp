#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace cargo_operations {

/// Unified DBA struct for YardSlot.
struct YardSlot {
    boost::uuids::uuid id{};
    boost::uuids::uuid id{};
    YardSlotCode code{};
    muscovite::dba::Decimal max_weight_kg{};
    std::int32_t max_tier{};
    bool has_power{};
    bool is_occupied{};

    /// Construct from a database row (stub — implementation in .cpp).
    // static auto from_row(const pqxx::row& row) -> YardSlot;

    /// Try to construct; returns nullopt on missing required field.
    // static auto try_from(const pqxx::row& row) -> std::optional<YardSlot>;
};

} // namespace cargo_operations
