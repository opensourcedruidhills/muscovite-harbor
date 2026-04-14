#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "passenger.hpp"
#include <optional>
#include <vector>

namespace passenger_terminal {

/// Repository interface for Passenger aggregate.
class PassengerRepository {
public:
    using Passengers = std::vector<Passenger>;

    virtual ~PassengerRepository() = default;

    [[nodiscard]] virtual auto find_by_id(const Passenger::Id& id) -> std::optional<Passenger> = 0;
    virtual auto save(const Passenger& entity) -> void = 0;
    virtual auto remove(const Passenger::Id& id) -> void = 0;
    [[nodiscard]] virtual auto find_all() -> Passengers = 0;
};

} // namespace passenger_terminal
