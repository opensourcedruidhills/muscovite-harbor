#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace cargo_operations {

/// Unified DBA struct for LoadPlan.
struct LoadPlan {
    boost::uuids::uuid id{};
    boost::uuids::uuid id{};
    boost::uuids::uuid voyage_id{};
    muscovite::dba::Timestamp created_at{};
    std::string status{};

    /// Construct from a database row (stub — implementation in .cpp).
    // static auto from_row(const pqxx::row& row) -> LoadPlan;

    /// Try to construct; returns nullopt on missing required field.
    // static auto try_from(const pqxx::row& row) -> std::optional<LoadPlan>;
};

} // namespace cargo_operations
