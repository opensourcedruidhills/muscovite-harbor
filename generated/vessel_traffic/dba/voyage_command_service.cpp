// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "voyage_command_service.hpp"

namespace vessel_traffic {

auto VoyageCommandService::create(const Voyage& entity) -> void {
    repository_.save(entity);
}

auto VoyageCommandService::update(const Voyage& entity) -> void {
    repository_.save(entity);
}

auto VoyageCommandService::remove(const Voyage::Id& id) -> void {
    repository_.remove(id);
}

} // namespace vessel_traffic
