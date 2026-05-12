#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace cargo_operations {

/// Unified DBA struct for Crane.
struct Crane {
    boost::uuids::uuid id{};
    boost::uuids::uuid id{};
    std::string name{};
    std::string crane_type{};
    muscovite::dba::Decimal max_lift_kg{};
    bool is_active{};

    /// Construct from a database row (stub — implementation in .cpp).
    // static auto from_row(const pqxx::row& row) -> Crane;

    /// Try to construct; returns nullopt on missing required field.
    // static auto try_from(const pqxx::row& row) -> std::optional<Crane>;
};

} // namespace cargo_operations
