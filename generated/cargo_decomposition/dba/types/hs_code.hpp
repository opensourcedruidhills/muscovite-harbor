#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>
#include <utility>

namespace cargo_decomposition {

/// Harmonised System tariff classification code
/// Strong type wrapper — prevents accidental mixing of types.
struct HSCode {
    using ValueType = std::string;

    ValueType value{};

    explicit HSCode() = default;
    explicit HSCode(ValueType v) : value{std::move(v)} {}

    [[nodiscard]] auto get() const noexcept -> const ValueType& { return value; }

    auto operator==(const HSCode&) const -> bool = default;
    auto operator<=>(const HSCode&) const = default;
};

} // namespace cargo_decomposition
