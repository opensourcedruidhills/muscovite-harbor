#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>

namespace spatial {

/// Value-object struct for GeoPoint.
struct GeoPoint {
    muscovite::dba::Decimal latitude{};
    muscovite::dba::Decimal longitude{};

    auto operator==(const GeoPoint&) const -> bool = default;
};

} // namespace spatial
