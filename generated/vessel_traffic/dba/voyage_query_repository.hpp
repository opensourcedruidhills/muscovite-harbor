#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "voyage.hpp"
#include <cstdint>
#include <optional>
#include <vector>

namespace vessel_traffic {

/// Query-side repository interface for Voyage aggregate.
/// Handles read operations (CQRS query side).
class VoyageQueryRepository {
public:
    virtual ~VoyageQueryRepository() = default;

    [[nodiscard]] virtual auto find_by_id(const Voyage::Id& id) -> std::optional<Voyage> = 0;
    [[nodiscard]] virtual auto find_all() -> std::vector<Voyage> = 0;
    [[nodiscard]] virtual auto count() -> std::int64_t = 0;
    [[nodiscard]] virtual auto find_by_vessels_by_eta(const muscovite::dba::Timestamp& from_eta, const muscovite::dba::Timestamp& to_eta) -> std::vector<Voyage> = 0;
};

} // namespace vessel_traffic
