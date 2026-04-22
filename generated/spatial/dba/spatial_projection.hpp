#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <cstdint>
#include <string>

namespace spatial {

/// Spatial reference system projection definition.
struct SpatialProjection {
    using Id = std::string;

    Id id{};
    std::string name{};
    std::int32_t srid{};
    std::string definition{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_name() const noexcept -> const std::string& { return name; }
    [[nodiscard]] auto get_srid() const noexcept -> std::int32_t { return srid; }
    [[nodiscard]] auto get_definition() const noexcept -> const std::string& { return definition; }
};

} // namespace spatial
