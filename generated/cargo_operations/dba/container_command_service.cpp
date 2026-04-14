// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "container_command_service.hpp"

namespace cargo_operations {

auto ContainerCommandService::create(const Container& entity) -> void {
    repository_.save(entity);
}

auto ContainerCommandService::update(const Container& entity) -> void {
    repository_.save(entity);
}

auto ContainerCommandService::remove(const Container::Id& id) -> void {
    repository_.remove(id);
}

} // namespace cargo_operations
