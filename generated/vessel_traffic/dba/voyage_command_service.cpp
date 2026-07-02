// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "voyage_command_service.hpp"
#include <stdexcept>

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

auto VoyageCommandService::announce_vessel(const boost::uuids::uuid& vessel_id, const muscovite::dba::Timestamp& eta, const std::string& cargo_category) -> void {
    auto entity = repository_.find_by_id(vessel_id);
    if (!entity) {
        throw std::runtime_error{"Voyage not found"};
    }
    entity->announce_vessel(eta, cargo_category);
    repository_.save(*entity);
}

auto VoyageCommandService::allocate_berth(const boost::uuids::uuid& berth_id) -> void {
    auto entity = repository_.find_by_id(berth_id);
    if (!entity) {
        throw std::runtime_error{"Voyage not found"};
    }
    entity->allocate_berth();
    repository_.save(*entity);
}

} // namespace vessel_traffic
