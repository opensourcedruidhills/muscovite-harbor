#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "voyage.hpp"
#include "voyage_query_repository.hpp"
#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace vessel_traffic {

/// Query service for Voyage aggregate.
/// Handles all read operations (CQRS query side).
class VoyageQueryService {
public:
    explicit VoyageQueryService(VoyageQueryRepository& repository)
        : repository_{repository} {}

    [[nodiscard]] auto find_by_id(const Voyage::Id& id) -> std::optional<Voyage>;
    [[nodiscard]] auto find_all() -> std::vector<Voyage>;
    [[nodiscard]] auto count() -> std::int64_t;
    [[nodiscard]] auto find_by_vessels_by_eta(const muscovite::dba::Timestamp& from_eta, const muscovite::dba::Timestamp& to_eta) -> std::vector<Voyage>;

private:
    VoyageQueryRepository& repository_;
};

} // namespace vessel_traffic
