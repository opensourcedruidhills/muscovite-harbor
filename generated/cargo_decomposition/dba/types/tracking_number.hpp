#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>
#include <utility>

namespace cargo_decomposition {

/// Parcel tracking number
/// Strong type wrapper — prevents accidental mixing of types.
struct TrackingNumber {
    using ValueType = std::string;

    ValueType value{};

    explicit TrackingNumber() = default;
    explicit TrackingNumber(ValueType v) : value{std::move(v)} {}

    [[nodiscard]] auto get() const noexcept -> const ValueType& { return value; }

    auto operator==(const TrackingNumber&) const -> bool = default;
    auto operator<=>(const TrackingNumber&) const = default;
};

} // namespace cargo_decomposition
