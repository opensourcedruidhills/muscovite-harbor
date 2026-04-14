#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "container.hpp"
#include "container_command_repository.hpp"
#include <memory>
#include <string>

namespace cargo_operations {

/// Command service for Container aggregate.
/// Handles all write operations (CQRS command side).
class ContainerCommandService {
public:
    explicit ContainerCommandService(ContainerCommandRepository& repository)
        : repository_{repository} {}

    auto create(const Container& entity) -> void;
    auto update(const Container& entity) -> void;
    auto remove(const Container::Id& id) -> void;

private:
    ContainerCommandRepository& repository_;
};

} // namespace cargo_operations
