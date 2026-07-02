// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "transfer_slot_domain_service.hpp"
#include "nlohmann/json.hpp"
#include <stdexcept>
#include <string_view>

namespace intermodal_transfer {

auto TransferSlotDomainService::create(const TransferSlot& entity) -> void {
    // Tier 1+2: field constraints and cross-field invariants (EntityValidator)
    auto tier12_errors = TransferSlotValidator::validate(entity);
    if (!tier12_errors.empty()) { throw std::runtime_error("Tier 1/2 validation failed"); }

    // Tier 3: plugin validation (PluginValidator)
    auto tier3_errors = TransferSlotPluginValidator::validate(entity);
    if (!tier3_errors.empty()) { throw std::runtime_error("Tier 3 validation failed"); }

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
    auto parent = query_service_.find_by_id(parent_id);
    if (!parent) {
        throw std::runtime_error("Parent TransferSlot not found");
    }
    command_service_.create(child);
}

auto TransferSlotDomainService::remove_truck_visit(const TransferSlot::Id& parent_id, const TruckVisit::Id& child_id) -> void {
    (void)parent_id;
    command_service_.remove(child_id);
}

} // namespace intermodal_transfer
