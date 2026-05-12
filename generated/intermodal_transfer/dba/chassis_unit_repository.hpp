#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>
#include <vector>

namespace intermodal_transfer {

/// Repository interface for ChassisUnit.
class ChassisUnitRepository {
public:
    virtual ~ChassisUnitRepository() = default;

    [[nodiscard]] virtual auto find_by_id(const std::string& id) const
        -> std::optional<ChassisUnit> = 0;

    [[nodiscard]] virtual auto find_all() const
        -> std::vector<ChassisUnit> = 0;

    virtual auto save(const ChassisUnit& entity) -> void = 0;

    virtual auto remove(const std::string& id) -> void = 0;
};

} // namespace intermodal_transfer
