// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "passenger_query_service.hpp"

namespace passenger_terminal {

auto PassengerQueryService::find_by_id(const Passenger::Id& id) -> std::optional<Passenger> {
    return repository_.find_by_id(id);
}

auto PassengerQueryService::find_all() -> std::vector<Passenger> {
    return repository_.find_all();
}

auto PassengerQueryService::count() -> std::int64_t {
    return repository_.count();
}

} // namespace passenger_terminal
