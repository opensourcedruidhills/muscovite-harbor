#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>
#include <utility>

namespace vessel_traffic {

/// IMO vessel identification number (7 digits)
/// Strong type wrapper — prevents accidental mixing of types.
struct IMONumber {
    using ValueType = std::string;

    ValueType value{};

    explicit IMONumber() = default;
    explicit IMONumber(ValueType v) : value{std::move(v)} {}

    [[nodiscard]] auto get() const noexcept -> const ValueType& { return value; }

    auto operator==(const IMONumber&) const -> bool = default;
    auto operator<=>(const IMONumber&) const = default;
};

} // namespace vessel_traffic
