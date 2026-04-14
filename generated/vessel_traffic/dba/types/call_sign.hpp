#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>
#include <utility>

namespace vessel_traffic {

/// International radio call sign
/// Strong type wrapper — prevents accidental mixing of types.
struct CallSign {
    using ValueType = std::string;

    ValueType value{};

    explicit CallSign() = default;
    explicit CallSign(ValueType v) : value{std::move(v)} {}

    [[nodiscard]] auto get() const noexcept -> const ValueType& { return value; }

    auto operator==(const CallSign&) const -> bool = default;
    auto operator<=>(const CallSign&) const = default;
};

} // namespace vessel_traffic
