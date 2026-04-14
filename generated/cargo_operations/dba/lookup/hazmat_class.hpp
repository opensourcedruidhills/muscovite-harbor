#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>
#include <string>

namespace cargo_operations {

/// IMO hazardous materials classification
/// Compile-time lookup table entry -- resolved at build time, not via DB SELECT.
struct HazmatClass {
    using Id = std::string;

    Id id{};
    std::string name{};
    std::string code{};

    // Extra fields
    std::string {};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_name() const noexcept -> const std::string& { return name; }
    [[nodiscard]] auto get_code() const noexcept -> const std::string& { return code; }
    [[nodiscard]] auto get_() const noexcept -> const std::string& { return ; }

    auto operator==(const HazmatClass&) const -> bool = default;
};

} // namespace cargo_operations
