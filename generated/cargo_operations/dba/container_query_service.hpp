#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "container.hpp"
#include "container_query_repository.hpp"
#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace cargo_operations {

/// Query service for Container aggregate.
/// Handles all read operations (CQRS query side).
class ContainerQueryService {
public:
    explicit ContainerQueryService(ContainerQueryRepository& repository)
        : repository_{repository} {}

    [[nodiscard]] auto find_by_id(const Container::Id& id) -> std::optional<Container>;
    [[nodiscard]] auto find_all() -> std::vector<Container>;
    [[nodiscard]] auto count() -> std::int64_t;

private:
    ContainerQueryRepository& repository_;
};

} // namespace cargo_operations
