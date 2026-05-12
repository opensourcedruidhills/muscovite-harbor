#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>

namespace cargo_decomposition {

/// Value-object struct for Dimensions.
struct Dimensions {
    muscovite::dba::Decimal length_cm{};
    muscovite::dba::Decimal width_cm{};
    muscovite::dba::Decimal height_cm{};

    auto operator==(const Dimensions&) const -> bool = default;
};

} // namespace cargo_decomposition
