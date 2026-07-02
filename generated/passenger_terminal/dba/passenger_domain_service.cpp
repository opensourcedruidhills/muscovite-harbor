// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "passenger_domain_service.hpp"
#include "nlohmann/json.hpp"
#include <stdexcept>
#include <string_view>

namespace passenger_terminal {

auto PassengerDomainService::create(const Passenger& entity) -> void {
    // Tier 1+2: field constraints and cross-field invariants (EntityValidator)
    auto tier12_errors = PassengerValidator::validate(entity);
    if (!tier12_errors.empty()) { throw std::runtime_error("Tier 1/2 validation failed"); }

    // Tier 3: plugin validation (PluginValidator)
    auto tier3_errors = PassengerPluginValidator::validate(entity);
    if (!tier3_errors.empty()) { throw std::runtime_error("Tier 3 validation failed"); }

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
    auto parent = query_service_.find_by_id(parent_id);
    if (!parent) {
        throw std::runtime_error("Parent Passenger not found");
    }
    command_service_.create(child);
}

auto PassengerDomainService::remove_boarding_pass(const Passenger::Id& parent_id, const BoardingPass::Id& child_id) -> void {
    (void)parent_id;
    command_service_.remove(child_id);
}

} // namespace passenger_terminal
