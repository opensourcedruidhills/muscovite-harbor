#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace harbour_control {

/// Unified DBA struct for SafetyZone.
struct SafetyZone {
    boost::uuids::uuid id{};
    boost::uuids::uuid id{};
    ZoneCode zone_code{};
    std::string zone_name{};
    std::string security_level{};
    std::int32_t max_hazmat_class{};
    bool is_restricted{};

    /// Construct from a database row (stub — implementation in .cpp).
    // static auto from_row(const pqxx::row& row) -> SafetyZone;

    /// Try to construct; returns nullopt on missing required field.
    // static auto try_from(const pqxx::row& row) -> std::optional<SafetyZone>;
};

} // namespace harbour_control
