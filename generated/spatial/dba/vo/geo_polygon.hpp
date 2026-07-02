#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>

namespace spatial {

/// Closed polygon encoded as a JSON-encoded list of GeoPoints.
/// Value object — compared by value, not identity.
struct GeoPolygon {
    std::string points{};

    [[nodiscard]] auto get_points() const noexcept -> const std::string& { return points; }

    auto operator==(const GeoPolygon&) const -> bool = default;
};

} // namespace spatial
