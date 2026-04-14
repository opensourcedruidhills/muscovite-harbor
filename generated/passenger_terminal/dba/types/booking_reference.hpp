#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>
#include <utility>

namespace passenger_terminal {

/// Passenger booking reference (e.g. AB123456)
/// Strong type wrapper — prevents accidental mixing of types.
struct BookingReference {
    using ValueType = std::string;

    ValueType value{};

    explicit BookingReference() = default;
    explicit BookingReference(ValueType v) : value{std::move(v)} {}

    [[nodiscard]] auto get() const noexcept -> const ValueType& { return value; }

    auto operator==(const BookingReference&) const -> bool = default;
    auto operator<=>(const BookingReference&) const = default;
};

} // namespace passenger_terminal
