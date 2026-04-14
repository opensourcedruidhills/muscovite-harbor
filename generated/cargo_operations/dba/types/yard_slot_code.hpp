#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>
#include <utility>

namespace cargo_operations {

/// Yard slot address: bay-row-tier (e.g. A01-03-02)
/// Strong type wrapper — prevents accidental mixing of types.
struct YardSlotCode {
    using ValueType = std::string;

    ValueType value{};

    explicit YardSlotCode() = default;
    explicit YardSlotCode(ValueType v) : value{std::move(v)} {}

    [[nodiscard]] auto get() const noexcept -> const ValueType& { return value; }

    auto operator==(const YardSlotCode&) const -> bool = default;
    auto operator<=>(const YardSlotCode&) const = default;
};

} // namespace cargo_operations
