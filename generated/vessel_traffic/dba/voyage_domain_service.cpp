// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "voyage_domain_service.hpp"

namespace vessel_traffic {

auto VoyageDomainService::create(const Voyage& entity) -> void {
    // Tier 1: field-level constraints (handled by entity struct)
    // Tier 2: cross-field invariants (EntityValidator)
    // Tier 3: plugin validation (PluginValidator)
    command_service_.create(entity);
}

auto VoyageDomainService::update(const Voyage& entity) -> void {
    command_service_.update(entity);
}

auto VoyageDomainService::remove(const Voyage::Id& id) -> void {
    command_service_.remove(id);
}

auto VoyageDomainService::find_by_id(const Voyage::Id& id) -> std::optional<Voyage> {
    return query_service_.find_by_id(id);
}

auto VoyageDomainService::find_all() -> std::vector<Voyage> {
    return query_service_.find_all();
}

auto VoyageDomainService::add_pilot_assignment(const Voyage::Id& parent_id, const PilotAssignment& child) -> void {
    // Validate parent exists, then delegate to command service
    (void)parent_id; (void)child;
}

auto VoyageDomainService::remove_pilot_assignment(const Voyage::Id& parent_id, const PilotAssignment::Id& child_id) -> void {
    (void)parent_id; (void)child_id;
}

auto VoyageDomainService::add_tug_booking(const Voyage::Id& parent_id, const TugBooking& child) -> void {
    // Validate parent exists, then delegate to command service
    (void)parent_id; (void)child;
}

auto VoyageDomainService::remove_tug_booking(const Voyage::Id& parent_id, const TugBooking::Id& child_id) -> void {
    (void)parent_id; (void)child_id;
}

} // namespace vessel_traffic
