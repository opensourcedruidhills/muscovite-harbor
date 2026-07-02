// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "container_command_service.hpp"
#include <stdexcept>

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

auto ContainerCommandService::place_container(const boost::uuids::uuid& slot_id, const std::int32_t& tier) -> void {
    auto entity = repository_.find_by_id(slot_id);
    if (!entity) {
        throw std::runtime_error{"Container not found"};
    }
    entity->place_container(tier);
    repository_.save(*entity);
}

auto ContainerCommandService::pick_container(const boost::uuids::uuid& picked_by) -> void {
    repository_.save(PickContainer{picked_by});
}

} // namespace cargo_operations
