#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>

namespace vessel_traffic {

/// Value-object struct for GeoPosition.
struct GeoPosition {
    muscovite::dba::Decimal latitude{};
    muscovite::dba::Decimal longitude{};

    auto operator==(const GeoPosition&) const -> bool = default;
};

} // namespace vessel_traffic
