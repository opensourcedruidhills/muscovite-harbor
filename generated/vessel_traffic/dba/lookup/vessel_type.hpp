#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>

namespace vessel_traffic {

/// Classification of vessel types
/// Compile-time lookup table entry -- resolved at build time, not via DB SELECT.
struct VesselType {
    using Id = std::string;

    Id id{};
    std::string name{};
    std::string code{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_name() const noexcept -> const std::string& { return name; }
    [[nodiscard]] auto get_code() const noexcept -> const std::string& { return code; }

    auto operator==(const VesselType&) const -> bool = default;
};

} // namespace vessel_traffic
