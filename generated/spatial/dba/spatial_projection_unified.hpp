#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace spatial {

/// Unified DBA struct for SpatialProjection.
struct SpatialProjection {
    boost::uuids::uuid id{};
    std::string name{};
    std::int32_t srid{};
    std::string definition{};

    /// Construct from a database row (stub — implementation in .cpp).
    // static auto from_row(const pqxx::row& row) -> SpatialProjection;

    /// Try to construct; returns nullopt on missing required field.
    // static auto try_from(const pqxx::row& row) -> std::optional<SpatialProjection>;
};

} // namespace spatial
