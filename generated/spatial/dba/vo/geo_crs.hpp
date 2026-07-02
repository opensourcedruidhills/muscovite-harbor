#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>

namespace spatial {

/// Coordinate reference system descriptor (ISO-6709 / EPSG registry).
/// Value object — compared by value, not identity.
struct GeoCRS {
    std::string identifier{};

    [[nodiscard]] auto get_identifier() const noexcept -> const std::string& { return identifier; }

    auto operator==(const GeoCRS&) const -> bool = default;
};

} // namespace spatial
