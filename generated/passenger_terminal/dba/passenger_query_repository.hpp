#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "passenger.hpp"
#include <cstdint>
#include <optional>
#include <vector>

namespace passenger_terminal {

/// Query-side repository interface for Passenger aggregate.
/// Handles read operations (CQRS query side).
class PassengerQueryRepository {
public:
    virtual ~PassengerQueryRepository() = default;

    [[nodiscard]] virtual auto find_by_id(const Passenger::Id& id) -> std::optional<Passenger> = 0;
    [[nodiscard]] virtual auto find_all() -> std::vector<Passenger> = 0;
    [[nodiscard]] virtual auto count() -> std::int64_t = 0;
};

} // namespace passenger_terminal
