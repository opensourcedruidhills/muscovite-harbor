#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "passenger.hpp"
#include <optional>
#include <string>
#include <vector>

namespace passenger_terminal {

/// Command-side repository interface for Passenger aggregate.
/// Handles write operations (create, update, delete).
class PassengerCommandRepository {
public:
    virtual ~PassengerCommandRepository() = default;

    virtual auto save(const Passenger& entity) -> void = 0;
    virtual auto remove(const Passenger::Id& id) -> void = 0;
    [[nodiscard]] virtual auto find_by_id(const Passenger::Id& id) -> std::optional<Passenger> = 0;
};

} // namespace passenger_terminal
