#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "container.hpp"
#include "container_command_service.hpp"
#include "container_query_service.hpp"
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace cargo_operations {

/// Domain service for Container aggregate.
/// Orchestrates three-tier validation pipeline and delegates to
/// CommandService (writes) and QueryService (reads).
class ContainerDomainService {
public:
    explicit ContainerDomainService(ContainerCommandService& command_service, ContainerQueryService& query_service)
        : command_service_{command_service}
        , query_service_{query_service} {}

    // Command operations (write side)
    auto create(const Container& entity) -> void;
    auto update(const Container& entity) -> void;
    auto remove(const Container::Id& id) -> void;

    // Query operations (read side — pass-through)
    [[nodiscard]] auto find_by_id(const Container::Id& id) -> std::optional<Container>;
    [[nodiscard]] auto find_all() -> std::vector<Container>;

private:
    ContainerCommandService& command_service_;
    ContainerQueryService& query_service_;
};

} // namespace cargo_operations
