// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "passenger_command_service.hpp"

namespace passenger_terminal {

auto PassengerCommandService::create(const Passenger& entity) -> void {
    repository_.save(entity);
}

auto PassengerCommandService::update(const Passenger& entity) -> void {
    repository_.save(entity);
}

auto PassengerCommandService::remove(const Passenger::Id& id) -> void {
    repository_.remove(id);
}

} // namespace passenger_terminal
