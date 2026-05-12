#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace security {

/// Unified DBA struct for AccessControlEntry.
struct AccessControlEntry {
    boost::uuids::uuid id{};
    std::string principal{};
    std::string resource{};
    std::string permission{};
    std::string effect{};

    /// Construct from a database row (stub — implementation in .cpp).
    // static auto from_row(const pqxx::row& row) -> AccessControlEntry;

    /// Try to construct; returns nullopt on missing required field.
    // static auto try_from(const pqxx::row& row) -> std::optional<AccessControlEntry>;
};

} // namespace security
