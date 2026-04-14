#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>
#include <utility>

namespace cargo_decomposition {

/// Pallet identifier (e.g. PLT-ABC12345)
/// Strong type wrapper — prevents accidental mixing of types.
struct PalletId {
    using ValueType = std::string;

    ValueType value{};

    explicit PalletId() = default;
    explicit PalletId(ValueType v) : value{std::move(v)} {}

    [[nodiscard]] auto get() const noexcept -> const ValueType& { return value; }

    auto operator==(const PalletId&) const -> bool = default;
    auto operator<=>(const PalletId&) const = default;
};

} // namespace cargo_decomposition
