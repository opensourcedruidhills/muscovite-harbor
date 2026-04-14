#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "container.hpp"
#include "container_event_store.hpp"
#include <cstdint>
#include <optional>
#include <string>
#include <vector>

namespace cargo_operations {

/// Event repository for Container (event-sourced aggregate).
/// Provides domain-level persistence using the event store.
class ContainerEventRepository {
public:
    explicit ContainerEventRepository(ContainerEventStore& store)
        : store_{store} {}

    /// Save entity by appending events.
    auto save(const Container& entity, std::int64_t version) -> void;

    /// Load entity from event store (snapshot + replay).
    [[nodiscard]] auto load(const boost::uuids::uuid& id) -> std::optional<Container>;

private:
    ContainerEventStore& store_;
};

} // namespace cargo_operations
