#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <cstdint>
#include <muscovite/dba/decimal.hpp>

namespace cargo_operations {

/// Value object — compared by value, not identity.
struct ContainerDimensions {
    std::int32_t length_ft{};
    muscovite::dba::Decimal weight_kg{};
    bool is_reefer{};

    [[nodiscard]] auto get_length_ft() const noexcept -> const std::int32_t& { return length_ft; }
    [[nodiscard]] auto get_weight_kg() const noexcept -> const muscovite::dba::Decimal& { return weight_kg; }
    [[nodiscard]] auto get_is_reefer() const noexcept -> const bool& { return is_reefer; }

    auto operator==(const ContainerDimensions&) const -> bool = default;
};

} // namespace cargo_operations
