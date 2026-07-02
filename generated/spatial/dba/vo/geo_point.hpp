#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "types/double_.hpp"

namespace spatial {

/// ISO-6709 geographic point: latitude, longitude, and optional altitude.
/// Value object — compared by value, not identity.
struct GeoPoint {
    Double lat{};
    Double lon{};
    Double alt{};

    [[nodiscard]] auto get_lat() const noexcept -> const Double& { return lat; }
    [[nodiscard]] auto get_lon() const noexcept -> const Double& { return lon; }
    [[nodiscard]] auto get_alt() const noexcept -> const Double& { return alt; }

    auto operator==(const GeoPoint&) const -> bool = default;
};

} // namespace spatial
