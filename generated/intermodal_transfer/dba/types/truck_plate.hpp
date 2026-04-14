#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>
#include <utility>

namespace intermodal_transfer {

/// Truck licence plate number
/// Strong type wrapper — prevents accidental mixing of types.
struct TruckPlate {
    using ValueType = std::string;

    ValueType value{};

    explicit TruckPlate() = default;
    explicit TruckPlate(ValueType v) : value{std::move(v)} {}

    [[nodiscard]] auto get() const noexcept -> const ValueType& { return value; }

    auto operator==(const TruckPlate&) const -> bool = default;
    auto operator<=>(const TruckPlate&) const = default;
};

} // namespace intermodal_transfer
