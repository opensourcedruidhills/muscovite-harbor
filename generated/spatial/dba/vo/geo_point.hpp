#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <muscovite/dba/decimal.hpp>

namespace spatial {

/// Simple latitude/longitude point.
/// Value object — compared by value, not identity.
struct GeoPoint {
    muscovite::dba::Decimal latitude{};
    muscovite::dba::Decimal longitude{};

    [[nodiscard]] auto get_latitude() const noexcept -> const muscovite::dba::Decimal& { return latitude; }
    [[nodiscard]] auto get_longitude() const noexcept -> const muscovite::dba::Decimal& { return longitude; }

    auto operator==(const GeoPoint&) const -> bool = default;
};

} // namespace spatial
