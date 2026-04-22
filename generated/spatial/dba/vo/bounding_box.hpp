#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <muscovite/dba/decimal.hpp>

namespace spatial {

/// Axis-aligned bounding box in geographic coordinates.
/// Value object — compared by value, not identity.
struct BoundingBox {
    muscovite::dba::Decimal min_lat{};
    muscovite::dba::Decimal min_lon{};
    muscovite::dba::Decimal max_lat{};
    muscovite::dba::Decimal max_lon{};

    [[nodiscard]] auto get_min_lat() const noexcept -> const muscovite::dba::Decimal& { return min_lat; }
    [[nodiscard]] auto get_min_lon() const noexcept -> const muscovite::dba::Decimal& { return min_lon; }
    [[nodiscard]] auto get_max_lat() const noexcept -> const muscovite::dba::Decimal& { return max_lat; }
    [[nodiscard]] auto get_max_lon() const noexcept -> const muscovite::dba::Decimal& { return max_lon; }

    auto operator==(const BoundingBox&) const -> bool = default;
};

} // namespace spatial
