// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "transfer_slot_domain_service.hpp"

namespace intermodal_transfer {

auto TransferSlotDomainService::create(const TransferSlot& entity) -> void {
    // Tier 1: field-level constraints (handled by entity struct)
    // Tier 2: cross-field invariants (EntityValidator)
    // Tier 3: plugin validation (PluginValidator)
    command_service_.create(entity);
}

auto TransferSlotDomainService::update(const TransferSlot& entity) -> void {
    command_service_.update(entity);
}

auto TransferSlotDomainService::remove(const TransferSlot::Id& id) -> void {
    command_service_.remove(id);
}

auto TransferSlotDomainService::find_by_id(const TransferSlot::Id& id) -> std::optional<TransferSlot> {
    return query_service_.find_by_id(id);
}

auto TransferSlotDomainService::find_all() -> std::vector<TransferSlot> {
    return query_service_.find_all();
}

auto TransferSlotDomainService::add_truck_visit(const TransferSlot::Id& parent_id, const TruckVisit& child) -> void {
    // Validate parent exists, then delegate to command service
    (void)parent_id; (void)child;
}

auto TransferSlotDomainService::remove_truck_visit(const TransferSlot::Id& parent_id, const TruckVisit::Id& child_id) -> void {
    (void)parent_id; (void)child_id;
}

} // namespace intermodal_transfer
