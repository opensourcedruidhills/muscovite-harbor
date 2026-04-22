#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>
#include <pqxx/pqxx>

namespace passenger_terminal {

/// Projection service for managing CQRS read model materialized views.
/// Only generated for contexts with ON_DEMAND or SCHEDULED projections.
class ProjectionService {
public:
    explicit ProjectionService(pqxx::connection& conn, int refresh_interval_seconds = 3600);
    virtual ~ProjectionService() = default;

    /// Refresh all materialized views in this context.
    auto refresh_all() -> void;

    auto refresh_departure_board() -> void;

    [[nodiscard]] auto is_stale_departure_board() const -> bool;
private:
    pqxx::connection& conn_;
    int refresh_interval_seconds_;
};

} // namespace passenger_terminal
