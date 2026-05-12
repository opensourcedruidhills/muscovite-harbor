#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>

namespace cargo_operations {

/// Value-object struct for ContainerDimensions.
struct ContainerDimensions {
    std::int32_t length_ft{};
    muscovite::dba::Decimal weight_kg{};
    bool is_reefer{};

    auto operator==(const ContainerDimensions&) const -> bool = default;
};

} // namespace cargo_operations
