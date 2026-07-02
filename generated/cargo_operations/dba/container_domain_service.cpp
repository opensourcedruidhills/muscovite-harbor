// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "container_domain_service.hpp"
#include "nlohmann/json.hpp"
#include <stdexcept>
#include <string_view>

namespace cargo_operations {

auto ContainerDomainService::create(const Container& entity) -> void {
    // Tier 1+2: field constraints and cross-field invariants (EntityValidator)
    auto tier12_errors = ContainerValidator::validate(entity);
    if (!tier12_errors.empty()) { throw std::runtime_error("Tier 1/2 validation failed"); }

    // Tier 3: plugin validation (PluginValidator)
    auto tier3_errors = ContainerPluginValidator::validate(entity);
    if (!tier3_errors.empty()) { throw std::runtime_error("Tier 3 validation failed"); }

    // Event-sourced: initial creation handled via DECIDE commands
}

auto ContainerDomainService::update(const Container& entity) -> void {
    // Event-sourced: updates handled via DECIDE commands + event_repository_
}

auto ContainerDomainService::remove(const Container::Id& id) -> void {
    // Event-sourced: removal handled via DECIDE commands + event_repository_
    (void)id;
}

auto ContainerDomainService::place_container(const Container::Id& id, const boost::uuids::uuid& slot_id, const std::int32_t& tier) -> void {
    auto entity = event_repository_.load(id);
    if (!entity) {
        throw std::runtime_error("Container not found");
    }

    auto decision = decide_place_container(*entity);

    if (!decision.events.empty()) {
        event_repository_.save(*entity, decision.events, 0);
    }

    for (const auto& effect : decision.effects) {
        unit_of_work_.plan_effect(effect);
    }

    for (const auto& event : decision.events) {
        std::visit([&](const auto& e) { policy_registry_.dispatch(e); }, event);
    }
    unit_of_work_.commit();
}

auto ContainerDomainService::decide_place_container(const Container& entity) const -> PlaceContainerDecision {
    auto decision = PlaceContainerDecision{};

    // REQUIRES: slot_empty
    if (!check_slot_empty(entity)) {
        throw PreconditionFailed{"slot_empty"};
    }
    // REQUIRES: weight_ok
    if (!check_weight_ok(entity)) {
        throw PreconditionFailed{"weight_ok"};
    }

    decision.events.push_back(ContainerPlaced{});

    const auto t = tier();
    decision.events.push_back(ContainerPlaced{.container_id = id(), .yard_slot_id = slot_id(), .tier = t(), .placed_at = NOW()});

    return decision;
}

auto ContainerDomainService::pick_container(const Container::Id& id, const boost::uuids::uuid& picked_by) -> void {
    auto entity = event_repository_.load(id);
    if (!entity) {
        throw std::runtime_error("Container not found");
    }

    auto decision = decide_pick_container(*entity);

    if (!decision.events.empty()) {
        event_repository_.save(*entity, decision.events, 0);
    }

    for (const auto& effect : decision.effects) {
        unit_of_work_.plan_effect(effect);
    }

    for (const auto& event : decision.events) {
        std::visit([&](const auto& e) { policy_registry_.dispatch(e); }, event);
    }
    unit_of_work_.commit();
}

auto ContainerDomainService::decide_pick_container(const Container& entity) const -> PickContainerDecision {
    auto decision = PickContainerDecision{};

    // REQUIRES: is_top
    if (!check_is_top(entity)) {
        throw PreconditionFailed{"is_top"};
    }

    decision.events.push_back(ContainerPicked{});

    decision.events.push_back(ContainerPicked{.container_id = id(), .yard_slot_id = yard_slot_id(), .picked_at = NOW()});

    return decision;
}

auto ContainerDomainService::find_by_id(const Container::Id& id) -> std::optional<Container> {
    return query_service_.find_by_id(id);
}

auto ContainerDomainService::find_all() -> std::vector<Container> {
    return query_service_.find_all();
}

} // namespace cargo_operations
