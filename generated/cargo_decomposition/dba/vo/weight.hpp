#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <muscovite/dba/decimal.hpp>

namespace cargo_decomposition {

/// Value object — compared by value, not identity.
struct Weight {
    muscovite::dba::Decimal value_kg{};

    [[nodiscard]] auto get_value_kg() const noexcept -> const muscovite::dba::Decimal& { return value_kg; }

    auto operator==(const Weight&) const -> bool = default;
};

} // namespace cargo_decomposition
