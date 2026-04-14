#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>
#include <utility>

namespace intermodal_transfer {

/// Transfer slot reference (e.g. TS-20260415-0001)
/// Strong type wrapper — prevents accidental mixing of types.
struct SlotReference {
    using ValueType = std::string;

    ValueType value{};

    explicit SlotReference() = default;
    explicit SlotReference(ValueType v) : value{std::move(v)} {}

    [[nodiscard]] auto get() const noexcept -> const ValueType& { return value; }

    auto operator==(const SlotReference&) const -> bool = default;
    auto operator<=>(const SlotReference&) const = default;
};

} // namespace intermodal_transfer
