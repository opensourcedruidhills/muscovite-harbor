#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "voyage.hpp"
#include "voyage_command_service.hpp"
#include "voyage_query_service.hpp"
#include "muscovite/dba/unit_of_work.hpp"
#include "policy/policies.hpp"
#include "domain/specifications.hpp"
#include "pilot_assignment.hpp"
#include "tug_booking.hpp"
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace vessel_traffic {

struct AnnounceVesselDecision {
    std::vector<VesselAnnounced> events;
    std::vector<EffectIntent> effects;
    bool ok{true};
};

struct AllocateBerthDecision {
    std::vector<BerthAllocated> events;
    std::vector<EffectIntent> effects;
    bool ok{true};
};

/// Domain service for Voyage aggregate.
/// Orchestrates three-tier validation pipeline and delegates to
/// CommandService (writes) and QueryService (reads).
class VoyageDomainService {
public:
    explicit VoyageDomainService(VoyageCommandService& command_service, VoyageQueryService& query_service, UnitOfWork& unit_of_work
    , EventPublisher* publisher = nullptr
    , CommandDispatcher* cmd_disp = nullptr
    , NotificationSender* notifier = nullptr
    , ServiceCaller* caller = nullptr
    )
        : command_service_{command_service}
        , query_service_{query_service}
        , unit_of_work_{unit_of_work}
    , policy_registry_{publisher, cmd_disp, notifier, caller}
        {}

    // Command operations (write side)
    auto create(const Voyage& entity) -> void;
    auto update(const Voyage& entity) -> void;
    auto remove(const Voyage::Id& id) -> void;
    auto announce_vessel(const Voyage::Id& id, const boost::uuids::uuid& vessel_id, const muscovite::dba::Timestamp& eta, const std::string& cargo_category) -> void;
    [[nodiscard]] auto decide_announce_vessel(const Voyage& entity) const -> AnnounceVesselDecision;
    auto allocate_berth(const Voyage::Id& id, const boost::uuids::uuid& berth_id) -> void;
    [[nodiscard]] auto decide_allocate_berth(const Voyage& entity) const -> AllocateBerthDecision;

    // Query operations (read side — pass-through)
    [[nodiscard]] auto find_by_id(const Voyage::Id& id) -> std::optional<Voyage>;
    [[nodiscard]] auto find_all() -> std::vector<Voyage>;

    // PilotAssignment child entity operations
    auto add_pilot_assignment(const Voyage::Id& parent_id, const PilotAssignment& child) -> void;
    auto remove_pilot_assignment(const Voyage::Id& parent_id, const PilotAssignment::Id& child_id) -> void;

    // TugBooking child entity operations
    auto add_tug_booking(const Voyage::Id& parent_id, const TugBooking& child) -> void;
    auto remove_tug_booking(const Voyage::Id& parent_id, const TugBooking::Id& child_id) -> void;

    // Specification-based filter methods
    [[nodiscard]] auto filter_by_available_berths(const muscovite::dba::Decimal& min_draft, const muscovite::dba::Decimal& min_loa, const bool& needs_crane, const muscovite::dba::Timestamp& from_time, const muscovite::dba::Timestamp& to_time) const -> std::vector<Berth>;
    [[nodiscard]] auto filter_by_vessels_by_eta(const muscovite::dba::Timestamp& from_eta, const muscovite::dba::Timestamp& to_eta) const -> std::vector<Voyage>;

private:
    VoyageCommandService& command_service_;
    VoyageQueryService& query_service_;
    UnitOfWork& unit_of_work_;
    PolicyRegistry policy_registry_;
};

} // namespace vessel_traffic
