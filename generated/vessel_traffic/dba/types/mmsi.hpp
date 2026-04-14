#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>
#include <utility>

namespace vessel_traffic {

/// Maritime Mobile Service Identity (9 digits)
/// Strong type wrapper — prevents accidental mixing of types.
struct MMSI {
    using ValueType = std::string;

    ValueType value{};

    explicit MMSI() = default;
    explicit MMSI(ValueType v) : value{std::move(v)} {}

    [[nodiscard]] auto get() const noexcept -> const ValueType& { return value; }

    auto operator==(const MMSI&) const -> bool = default;
    auto operator<=>(const MMSI&) const = default;
};

} // namespace vessel_traffic
