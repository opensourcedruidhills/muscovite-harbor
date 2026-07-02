// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "load_plan_domain_service.hpp"
#include "nlohmann/json.hpp"
#include <stdexcept>
#include <string_view>

namespace cargo_operations {

auto LoadPlanDomainService::create(const LoadPlan& entity) -> void {
    // Tier 1+2: field constraints and cross-field invariants (EntityValidator)
    auto tier12_errors = LoadPlanValidator::validate(entity);
    if (!tier12_errors.empty()) { throw std::runtime_error("Tier 1/2 validation failed"); }

    // Tier 3: plugin validation (PluginValidator)
    auto tier3_errors = LoadPlanPluginValidator::validate(entity);
    if (!tier3_errors.empty()) { throw std::runtime_error("Tier 3 validation failed"); }

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
    auto parent = query_service_.find_by_id(parent_id);
    if (!parent) {
        throw std::runtime_error("Parent LoadPlan not found");
    }
    command_service_.create(child);
}

auto LoadPlanDomainService::remove_discharge_sequence(const LoadPlan::Id& parent_id, const DischargeSequence::Id& child_id) -> void {
    (void)parent_id;
    command_service_.remove(child_id);
}

} // namespace cargo_operations
