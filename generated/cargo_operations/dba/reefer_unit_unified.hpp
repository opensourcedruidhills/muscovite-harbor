#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace cargo_operations {

/// Unified DBA struct for ReeferUnit.
struct ReeferUnit {
    boost::uuids::uuid id{};
    boost::uuids::uuid id{};
    boost::uuids::uuid container_id{};
    muscovite::dba::Decimal target_temp_c{};
    muscovite::dba::Decimal current_temp_c{};
    bool is_powered{};

    /// Construct from a database row (stub — implementation in .cpp).
    // static auto from_row(const pqxx::row& row) -> ReeferUnit;

    /// Try to construct; returns nullopt on missing required field.
    // static auto try_from(const pqxx::row& row) -> std::optional<ReeferUnit>;
};

} // namespace cargo_operations
