// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "container_domain_service.hpp"
#include <stdexcept>

namespace cargo_operations {

auto ContainerDomainService::create(const Container& entity) -> void {
    // Tier 1: field-level constraints (handled by entity struct)
    // Tier 2: cross-field invariants (EntityValidator)
    // Tier 3: plugin validation (PluginValidator)
    command_service_.create(entity);
}

auto ContainerDomainService::update(const Container& entity) -> void {
    command_service_.update(entity);
}

auto ContainerDomainService::remove(const Container::Id& id) -> void {
    command_service_.remove(id);
}

auto ContainerDomainService::find_by_id(const Container::Id& id) -> std::optional<Container> {
    return query_service_.find_by_id(id);
}

auto ContainerDomainService::find_all() -> std::vector<Container> {
    return query_service_.find_all();
}

} // namespace cargo_operations
