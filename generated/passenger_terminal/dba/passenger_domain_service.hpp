#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "passenger.hpp"
#include "passenger_command_service.hpp"
#include "passenger_query_service.hpp"
#include "boarding_pass.hpp"
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace passenger_terminal {

/// Domain service for Passenger aggregate.
/// Orchestrates three-tier validation pipeline and delegates to
/// CommandService (writes) and QueryService (reads).
class PassengerDomainService {
public:
    explicit PassengerDomainService(PassengerCommandService& command_service, PassengerQueryService& query_service)
        : command_service_{command_service}
        , query_service_{query_service} {}

    // Command operations (write side)
    auto create(const Passenger& entity) -> void;
    auto update(const Passenger& entity) -> void;
    auto remove(const Passenger::Id& id) -> void;

    // Query operations (read side — pass-through)
    [[nodiscard]] auto find_by_id(const Passenger::Id& id) -> std::optional<Passenger>;
    [[nodiscard]] auto find_all() -> std::vector<Passenger>;

    // BoardingPass child entity operations
    auto add_boarding_pass(const Passenger::Id& parent_id, const BoardingPass& child) -> void;
    auto remove_boarding_pass(const Passenger::Id& parent_id, const BoardingPass::Id& child_id) -> void;

private:
    PassengerCommandService& command_service_;
    PassengerQueryService& query_service_;
};

} // namespace passenger_terminal
