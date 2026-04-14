#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "voyage.hpp"
#include "voyage_command_repository.hpp"
#include <memory>
#include <string>

namespace vessel_traffic {

/// Command service for Voyage aggregate.
/// Handles all write operations (CQRS command side).
class VoyageCommandService {
public:
    explicit VoyageCommandService(VoyageCommandRepository& repository)
        : repository_{repository} {}

    auto create(const Voyage& entity) -> void;
    auto update(const Voyage& entity) -> void;
    auto remove(const Voyage::Id& id) -> void;

private:
    VoyageCommandRepository& repository_;
};

} // namespace vessel_traffic
