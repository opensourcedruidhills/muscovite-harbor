#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace vessel_traffic {

/// Value object — compared by value, not identity.
struct GeoPosition {
    muscovite::dba::Decimal latitude{};
    muscovite::dba::Decimal longitude{};

    [[nodiscard]] auto get_latitude() const noexcept -> const muscovite::dba::Decimal& { return latitude; }
    [[nodiscard]] auto get_longitude() const noexcept -> const muscovite::dba::Decimal& { return longitude; }

    auto operator==(const GeoPosition&) const -> bool = default;
};

} // namespace vessel_traffic
