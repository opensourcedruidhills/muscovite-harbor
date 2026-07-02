#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>

namespace spatial {

/// Axis-aligned bounding region defined by northeast and southwest corners.
/// Value object — compared by value, not identity.
struct GeoRegion {
    std::string ne{};
    std::string sw{};

    [[nodiscard]] auto get_ne() const noexcept -> const std::string& { return ne; }
    [[nodiscard]] auto get_sw() const noexcept -> const std::string& { return sw; }

    auto operator==(const GeoRegion&) const -> bool = default;
};

} // namespace spatial
