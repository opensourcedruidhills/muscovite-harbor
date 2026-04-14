#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "voyage.hpp"
#include "voyage_command_service.hpp"
#include "voyage_query_service.hpp"
#include "pilot_assignment.hpp"
#include "tug_booking.hpp"
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace vessel_traffic {

/// Domain service for Voyage aggregate.
/// Orchestrates three-tier validation pipeline and delegates to
/// CommandService (writes) and QueryService (reads).
class VoyageDomainService {
public:
    explicit VoyageDomainService(VoyageCommandService& command_service, VoyageQueryService& query_service)
        : command_service_{command_service}
        , query_service_{query_service} {}

    // Command operations (write side)
    auto create(const Voyage& entity) -> void;
    auto update(const Voyage& entity) -> void;
    auto remove(const Voyage::Id& id) -> void;

    // Query operations (read side — pass-through)
    [[nodiscard]] auto find_by_id(const Voyage::Id& id) -> std::optional<Voyage>;
    [[nodiscard]] auto find_all() -> std::vector<Voyage>;

    // PilotAssignment child entity operations
    auto add_pilot_assignment(const Voyage::Id& parent_id, const PilotAssignment& child) -> void;
    auto remove_pilot_assignment(const Voyage::Id& parent_id, const PilotAssignment::Id& child_id) -> void;

    // TugBooking child entity operations
    auto add_tug_booking(const Voyage::Id& parent_id, const TugBooking& child) -> void;
    auto remove_tug_booking(const Voyage::Id& parent_id, const TugBooking::Id& child_id) -> void;

private:
    VoyageCommandService& command_service_;
    VoyageQueryService& query_service_;
};

} // namespace vessel_traffic
