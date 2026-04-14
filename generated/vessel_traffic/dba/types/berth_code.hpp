#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>
#include <utility>

namespace vessel_traffic {

/// Berth identifier (e.g. NQ-12, SC-3)
/// Strong type wrapper — prevents accidental mixing of types.
struct BerthCode {
    using ValueType = std::string;

    ValueType value{};

    explicit BerthCode() = default;
    explicit BerthCode(ValueType v) : value{std::move(v)} {}

    [[nodiscard]] auto get() const noexcept -> const ValueType& { return value; }

    auto operator==(const BerthCode&) const -> bool = default;
    auto operator<=>(const BerthCode&) const = default;
};

} // namespace vessel_traffic
