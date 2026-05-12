#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>
#include <vector>

namespace cargo_operations {

/// Repository interface for Crane.
class CraneRepository {
public:
    virtual ~CraneRepository() = default;

    [[nodiscard]] virtual auto find_by_id(const std::string& id) const
        -> std::optional<Crane> = 0;

    [[nodiscard]] virtual auto find_all() const
        -> std::vector<Crane> = 0;

    virtual auto save(const Crane& entity) -> void = 0;

    virtual auto remove(const std::string& id) -> void = 0;
};

} // namespace cargo_operations
