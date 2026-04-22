#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <cstdint>
#include <muscovite/dba/decimal.hpp>

namespace spatial {

/// Geographic coordinate with optional altitude and spatial reference.
struct Coordinate {
    using Id = std::string;

    Id id{};
    muscovite::dba::Decimal latitude{};
    muscovite::dba::Decimal longitude{};
    muscovite::dba::Decimal altitude{};
    std::int32_t srid{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_latitude() const noexcept -> const muscovite::dba::Decimal& { return latitude; }
    [[nodiscard]] auto get_longitude() const noexcept -> const muscovite::dba::Decimal& { return longitude; }
    [[nodiscard]] auto get_altitude() const noexcept -> const muscovite::dba::Decimal& { return altitude; }
    [[nodiscard]] auto get_srid() const noexcept -> std::int32_t { return srid; }
};

} // namespace spatial
