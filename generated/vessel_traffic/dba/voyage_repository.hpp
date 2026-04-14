#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "voyage.hpp"
#include <optional>
#include <vector>

namespace vessel_traffic {

/// Repository interface for Voyage aggregate.
class VoyageRepository {
public:
    using Voyages = std::vector<Voyage>;

    virtual ~VoyageRepository() = default;

    [[nodiscard]] virtual auto find_by_id(const Voyage::Id& id) -> std::optional<Voyage> = 0;
    virtual auto save(const Voyage& entity) -> void = 0;
    virtual auto remove(const Voyage::Id& id) -> void = 0;
    [[nodiscard]] virtual auto find_all() -> Voyages = 0;

    // Custom repository methods
    [[nodiscard]] virtual auto find_by_eta(const muscovite::dba::Timestamp& from_eta, const muscovite::dba::Timestamp& to_eta) -> Voyage = 0;
    [[nodiscard]] virtual auto find_conflicting_berths(const boost::uuids::uuid& berth_id, const muscovite::dba::Timestamp& from_time, const muscovite::dba::Timestamp& to_time) -> Voyage = 0;
    [[nodiscard]] virtual auto find_active_by_vessel(const boost::uuids::uuid& vessel_id) -> Voyage = 0;
};

} // namespace vessel_traffic
