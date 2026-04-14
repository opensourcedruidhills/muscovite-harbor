#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "container.hpp"
#include <cstdint>
#include <optional>
#include <string>
#include <variant>
#include <vector>

namespace cargo_operations {

/// Event store interface for Container (event-sourced aggregate).
/// Dual-write pattern: events + snapshot + entity table in single transaction.
class ContainerEventStore {
public:
    virtual ~ContainerEventStore() = default;

    /// Append an event for the given aggregate.
    virtual auto append(const boost::uuids::uuid& aggregate_id, std::int64_t expected_version,
                        const std::string& event_type, const std::string& payload) -> void = 0;

    /// Load the latest snapshot for an aggregate.
    [[nodiscard]] virtual auto load_snapshot(const boost::uuids::uuid& aggregate_id) -> std::optional<Container> = 0;

    /// Load events from a given version.
    [[nodiscard]] virtual auto load_events(const boost::uuids::uuid& aggregate_id, std::int64_t from_version) -> std::vector<std::string> = 0;
};

} // namespace cargo_operations
