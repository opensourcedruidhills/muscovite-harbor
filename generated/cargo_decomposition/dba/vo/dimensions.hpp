#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <muscovite/dba/decimal.hpp>

namespace cargo_decomposition {

/// Value object — compared by value, not identity.
struct Dimensions {
    muscovite::dba::Decimal length_cm{};
    muscovite::dba::Decimal width_cm{};
    muscovite::dba::Decimal height_cm{};

    [[nodiscard]] auto get_length_cm() const noexcept -> const muscovite::dba::Decimal& { return length_cm; }
    [[nodiscard]] auto get_width_cm() const noexcept -> const muscovite::dba::Decimal& { return width_cm; }
    [[nodiscard]] auto get_height_cm() const noexcept -> const muscovite::dba::Decimal& { return height_cm; }

    auto operator==(const Dimensions&) const -> bool = default;
};

} // namespace cargo_decomposition
