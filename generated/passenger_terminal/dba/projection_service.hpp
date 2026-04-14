#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>

namespace passenger_terminal {

/// Projection service for managing CQRS read model materialized views.
/// Only generated for contexts with ON_DEMAND or SCHEDULED projections.
class ProjectionService {
public:
    virtual ~ProjectionService() = default;

    /// Refresh all materialized views in this context.
    auto refresh_all() -> void;

    auto refresh_departure_board() -> void;

    [[nodiscard]] auto is_stale_departure_board() const -> bool;
};

} // namespace passenger_terminal
