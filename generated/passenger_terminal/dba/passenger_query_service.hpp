#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "passenger.hpp"
#include "passenger_query_repository.hpp"
#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace passenger_terminal {

/// Query service for Passenger aggregate.
/// Handles all read operations (CQRS query side).
class PassengerQueryService {
public:
    explicit PassengerQueryService(PassengerQueryRepository& repository)
        : repository_{repository} {}

    [[nodiscard]] auto find_by_id(const Passenger::Id& id) -> std::optional<Passenger>;
    [[nodiscard]] auto find_all() -> std::vector<Passenger>;
    [[nodiscard]] auto count() -> std::int64_t;

private:
    PassengerQueryRepository& repository_;
};

} // namespace passenger_terminal
