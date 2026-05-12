#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace cargo_decomposition {

/// Unified DBA struct for BreakBulkItem.
struct BreakBulkItem {
    boost::uuids::uuid id{};
    boost::uuids::uuid id{};
    boost::uuids::uuid container_id{};
    std::string item_type{};
    muscovite::dba::Decimal weight_kg{};
    bool requires_crane{};

    /// Construct from a database row (stub — implementation in .cpp).
    // static auto from_row(const pqxx::row& row) -> BreakBulkItem;

    /// Try to construct; returns nullopt on missing required field.
    // static auto try_from(const pqxx::row& row) -> std::optional<BreakBulkItem>;
};

} // namespace cargo_decomposition
