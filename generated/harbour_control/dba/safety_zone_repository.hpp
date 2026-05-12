#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>
#include <vector>

namespace harbour_control {

/// Repository interface for SafetyZone.
class SafetyZoneRepository {
public:
    virtual ~SafetyZoneRepository() = default;

    [[nodiscard]] virtual auto find_by_id(const std::string& id) const
        -> std::optional<SafetyZone> = 0;

    [[nodiscard]] virtual auto find_all() const
        -> std::vector<SafetyZone> = 0;

    virtual auto save(const SafetyZone& entity) -> void = 0;

    virtual auto remove(const std::string& id) -> void = 0;
};

} // namespace harbour_control
