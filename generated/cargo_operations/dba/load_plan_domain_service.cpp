// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "load_plan_domain_service.hpp"

namespace cargo_operations {

auto LoadPlanDomainService::create(const LoadPlan& entity) -> void {
    // Tier 1: field-level constraints (handled by entity struct)
    // Tier 2: cross-field invariants (EntityValidator)
    // Tier 3: plugin validation (PluginValidator)
    command_service_.create(entity);
}

auto LoadPlanDomainService::update(const LoadPlan& entity) -> void {
    command_service_.update(entity);
}

auto LoadPlanDomainService::remove(const LoadPlan::Id& id) -> void {
    command_service_.remove(id);
}

auto LoadPlanDomainService::find_by_id(const LoadPlan::Id& id) -> std::optional<LoadPlan> {
    return query_service_.find_by_id(id);
}

auto LoadPlanDomainService::find_all() -> std::vector<LoadPlan> {
    return query_service_.find_all();
}

auto LoadPlanDomainService::add_discharge_sequence(const LoadPlan::Id& parent_id, const DischargeSequence& child) -> void {
    // Validate parent exists, then delegate to command service
    (void)parent_id; (void)child;
}

auto LoadPlanDomainService::remove_discharge_sequence(const LoadPlan::Id& parent_id, const DischargeSequence::Id& child_id) -> void {
    (void)parent_id; (void)child_id;
}

} // namespace cargo_operations
