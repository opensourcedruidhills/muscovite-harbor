#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>

namespace vessel_traffic {

/// Value-object struct for Dimensions.
struct Dimensions {
    muscovite::dba::Decimal loa_metres{};
    muscovite::dba::Decimal beam_metres{};
    muscovite::dba::Decimal draft_metres{};

    auto operator==(const Dimensions&) const -> bool = default;
};

} // namespace vessel_traffic
