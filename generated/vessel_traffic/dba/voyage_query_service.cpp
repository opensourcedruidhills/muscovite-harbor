// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "voyage_query_service.hpp"

namespace vessel_traffic {

auto VoyageQueryService::find_by_id(const Voyage::Id& id) -> std::optional<Voyage> {
    return repository_.find_by_id(id);
}

auto VoyageQueryService::find_all() -> std::vector<Voyage> {
    return repository_.find_all();
}

auto VoyageQueryService::count() -> std::int64_t {
    return repository_.count();
}

auto VoyageQueryService::find_by_vessels_by_eta(const muscovite::dba::Timestamp& from_eta, const muscovite::dba::Timestamp& to_eta) -> std::vector<Voyage> {
    return repository_.find_by_vessels_by_eta(from_eta, to_eta);
}

} // namespace vessel_traffic
