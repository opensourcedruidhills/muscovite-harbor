#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>
#include <vector>

namespace spatial {

/// Repository interface for Region.
class RegionRepository {
public:
    virtual ~RegionRepository() = default;

    [[nodiscard]] virtual auto find_by_id(const std::string& id) const
        -> std::optional<Region> = 0;

    [[nodiscard]] virtual auto find_all() const
        -> std::vector<Region> = 0;

    virtual auto save(const Region& entity) -> void = 0;

    virtual auto remove(const std::string& id) -> void = 0;
};

} // namespace spatial
