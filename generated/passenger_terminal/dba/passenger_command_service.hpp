#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "passenger.hpp"
#include "passenger_command_repository.hpp"
#include <memory>
#include <string>

namespace passenger_terminal {

/// Command service for Passenger aggregate.
/// Handles all write operations (CQRS command side).
class PassengerCommandService {
public:
    explicit PassengerCommandService(PassengerCommandRepository& repository)
        : repository_{repository} {}

    auto create(const Passenger& entity) -> void;
    auto update(const Passenger& entity) -> void;
    auto remove(const Passenger::Id& id) -> void;

private:
    PassengerCommandRepository& repository_;
};

} // namespace passenger_terminal
