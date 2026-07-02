// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "voyage_domain_service.hpp"
#include "nlohmann/json.hpp"
#include <stdexcept>
#include <string_view>

namespace vessel_traffic {

auto VoyageDomainService::create(const Voyage& entity) -> void {
    // Tier 1+2: field constraints and cross-field invariants (EntityValidator)
    auto tier12_errors = VoyageValidator::validate(entity);
    if (!tier12_errors.empty()) { throw std::runtime_error("Tier 1/2 validation failed"); }

    // Tier 3: plugin validation (PluginValidator)
    auto tier3_errors = VoyagePluginValidator::validate(entity);
    if (!tier3_errors.empty()) { throw std::runtime_error("Tier 3 validation failed"); }

    command_service_.create(entity);
}

auto VoyageDomainService::update(const Voyage& entity) -> void {
    command_service_.update(entity);
}

auto VoyageDomainService::remove(const Voyage::Id& id) -> void {
    command_service_.remove(id);
}

auto VoyageDomainService::announce_vessel(const Voyage::Id& id, const boost::uuids::uuid& vessel_id, const muscovite::dba::Timestamp& eta, const std::string& cargo_category) -> void {
    auto entity = query_service_.find_by_id(id);
    if (!entity) {
        throw std::runtime_error("Voyage not found");
    }

    auto decision = decide_announce_vessel(*entity);

    command_service_.announce_vessel(vessel_id, eta, cargo_category);

    for (const auto& effect : decision.effects) {
        unit_of_work_.plan_effect(effect);
    }

    for (const auto& event : decision.events) {
        std::visit([&](const auto& e) {
            using T = std::decay_t<decltype(e)>;
            std::string_view event_type_name;
            if constexpr (std::is_same_v<T, VesselAnnounced>) {
                event_type_name = "VesselAnnounced";
            }
            unit_of_work_.add_event(DomainEvent::create(
                event_type_name, entity->id, "Voyage", "{}"));
            policy_registry_.dispatch(e);
        }, event);
    }
    unit_of_work_.commit();
}

auto VoyageDomainService::decide_announce_vessel(const Voyage& entity) const -> AnnounceVesselDecision {
    auto decision = AnnounceVesselDecision{};

    // REQUIRES: vessel_exists
    if (!check_vessel_exists(entity)) {
        throw PreconditionFailed{"vessel_exists"};
    }

    decision.events.push_back(VesselAnnounced{});

    const auto vn = CONCAT('V-', TO_CHAR(NOW(), 'YYYYMMDD'), '-', SUBSTR(MD5(RANDOM()::TEXT),1,6));
    decision.events.push_back(VesselAnnounced{.voyage_id = id(), .vessel_id = vessel_id(), .eta = eta()});

    return decision;
}

auto VoyageDomainService::allocate_berth(const Voyage::Id& id, const boost::uuids::uuid& berth_id) -> void {
    auto entity = query_service_.find_by_id(id);
    if (!entity) {
        throw std::runtime_error("Voyage not found");
    }

    auto decision = decide_allocate_berth(*entity);

    command_service_.allocate_berth(berth_id);

    for (const auto& effect : decision.effects) {
        unit_of_work_.plan_effect(effect);
    }

    for (const auto& event : decision.events) {
        std::visit([&](const auto& e) {
            using T = std::decay_t<decltype(e)>;
            std::string_view event_type_name;
            if constexpr (std::is_same_v<T, BerthAllocated>) {
                event_type_name = "BerthAllocated";
            }
            unit_of_work_.add_event(DomainEvent::create(
                event_type_name, entity->id, "Voyage", "{}"));
            policy_registry_.dispatch(e);
        }, event);
    }
    unit_of_work_.commit();
}

auto VoyageDomainService::decide_allocate_berth(const Voyage& entity) const -> AllocateBerthDecision {
    auto decision = AllocateBerthDecision{};

    // REQUIRES: voyage_announced
    if (!check_voyage_announced(entity)) {
        throw PreconditionFailed{"voyage_announced"};
    }
    // REQUIRES: berth_available
    if (!check_berth_available(entity)) {
        throw PreconditionFailed{"berth_available"};
    }

    decision.events.push_back(BerthAllocated{});

    decision.events.push_back(BerthAllocated{.voyage_id = id(), .berth_id = berth_id()});

    return decision;
}

auto VoyageDomainService::find_by_id(const Voyage::Id& id) -> std::optional<Voyage> {
    return query_service_.find_by_id(id);
}

auto VoyageDomainService::find_all() -> std::vector<Voyage> {
    return query_service_.find_all();
}

auto VoyageDomainService::add_pilot_assignment(const Voyage::Id& parent_id, const PilotAssignment& child) -> void {
    auto parent = query_service_.find_by_id(parent_id);
    if (!parent) {
        throw std::runtime_error("Parent Voyage not found");
    }
    command_service_.create(child);
}

auto VoyageDomainService::remove_pilot_assignment(const Voyage::Id& parent_id, const PilotAssignment::Id& child_id) -> void {
    (void)parent_id;
    command_service_.remove(child_id);
}

auto VoyageDomainService::add_tug_booking(const Voyage::Id& parent_id, const TugBooking& child) -> void {
    auto parent = query_service_.find_by_id(parent_id);
    if (!parent) {
        throw std::runtime_error("Parent Voyage not found");
    }
    command_service_.create(child);
}

auto VoyageDomainService::remove_tug_booking(const Voyage::Id& parent_id, const TugBooking::Id& child_id) -> void {
    (void)parent_id;
    command_service_.remove(child_id);
}

auto VoyageDomainService::filter_by_available_berths(const muscovite::dba::Decimal& min_draft, const muscovite::dba::Decimal& min_loa, const bool& needs_crane, const muscovite::dba::Timestamp& from_time, const muscovite::dba::Timestamp& to_time) const -> std::vector<Berth> {
    AvailableBerthsSpec spec{min_draft, min_loa, needs_crane, from_time, to_time};
    return query_service_.filter_by_spec(spec);
}

auto VoyageDomainService::filter_by_vessels_by_eta(const muscovite::dba::Timestamp& from_eta, const muscovite::dba::Timestamp& to_eta) const -> std::vector<Voyage> {
    VesselsByETASpec spec{from_eta, to_eta};
    return query_service_.filter_by_spec(spec);
}

} // namespace vessel_traffic
