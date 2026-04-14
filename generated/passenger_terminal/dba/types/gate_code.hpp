#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>
#include <utility>

namespace passenger_terminal {

/// Terminal gate identifier (e.g. G1, G12)
/// Strong type wrapper — prevents accidental mixing of types.
struct GateCode {
    using ValueType = std::string;

    ValueType value{};

    explicit GateCode() = default;
    explicit GateCode(ValueType v) : value{std::move(v)} {}

    [[nodiscard]] auto get() const noexcept -> const ValueType& { return value; }

    auto operator==(const GateCode&) const -> bool = default;
    auto operator<=>(const GateCode&) const = default;
};

} // namespace passenger_terminal
