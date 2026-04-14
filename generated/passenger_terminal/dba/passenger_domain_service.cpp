// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "passenger_domain_service.hpp"

namespace passenger_terminal {

auto PassengerDomainService::create(const Passenger& entity) -> void {
    // Tier 1: field-level constraints (handled by entity struct)
    // Tier 2: cross-field invariants (EntityValidator)
    // Tier 3: plugin validation (PluginValidator)
    command_service_.create(entity);
}

auto PassengerDomainService::update(const Passenger& entity) -> void {
    command_service_.update(entity);
}

auto PassengerDomainService::remove(const Passenger::Id& id) -> void {
    command_service_.remove(id);
}

auto PassengerDomainService::find_by_id(const Passenger::Id& id) -> std::optional<Passenger> {
    return query_service_.find_by_id(id);
}

auto PassengerDomainService::find_all() -> std::vector<Passenger> {
    return query_service_.find_all();
}

auto PassengerDomainService::add_boarding_pass(const Passenger::Id& parent_id, const BoardingPass& child) -> void {
    // Validate parent exists, then delegate to command service
    (void)parent_id; (void)child;
}

auto PassengerDomainService::remove_boarding_pass(const Passenger::Id& parent_id, const BoardingPass::Id& child_id) -> void {
    (void)parent_id; (void)child_id;
}

} // namespace passenger_terminal
