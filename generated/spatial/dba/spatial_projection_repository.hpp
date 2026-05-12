#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>
#include <vector>

namespace spatial {

/// Repository interface for SpatialProjection.
class SpatialProjectionRepository {
public:
    virtual ~SpatialProjectionRepository() = default;

    [[nodiscard]] virtual auto find_by_id(const std::string& id) const
        -> std::optional<SpatialProjection> = 0;

    [[nodiscard]] virtual auto find_all() const
        -> std::vector<SpatialProjection> = 0;

    virtual auto save(const SpatialProjection& entity) -> void = 0;

    virtual auto remove(const std::string& id) -> void = 0;
};

} // namespace spatial
