#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "voyage.hpp"
#include <optional>
#include <string>
#include <vector>

namespace vessel_traffic {

/// Command-side repository interface for Voyage aggregate.
/// Handles write operations (create, update, delete).
class VoyageCommandRepository {
public:
    virtual ~VoyageCommandRepository() = default;

    virtual auto save(const Voyage& entity) -> void = 0;
    virtual auto remove(const Voyage::Id& id) -> void = 0;
    [[nodiscard]] virtual auto find_by_id(const Voyage::Id& id) -> std::optional<Voyage> = 0;
};

} // namespace vessel_traffic
