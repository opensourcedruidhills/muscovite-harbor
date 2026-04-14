#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>
#include <utility>

namespace cargo_operations {

/// ISO 6346 container number (4 letters + 7 digits)
/// Strong type wrapper — prevents accidental mixing of types.
struct ContainerNumber {
    using ValueType = std::string;

    ValueType value{};

    explicit ContainerNumber() = default;
    explicit ContainerNumber(ValueType v) : value{std::move(v)} {}

    [[nodiscard]] auto get() const noexcept -> const ValueType& { return value; }

    auto operator==(const ContainerNumber&) const -> bool = default;
    auto operator<=>(const ContainerNumber&) const = default;
};

} // namespace cargo_operations
