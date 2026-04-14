#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "container.hpp"
#include <cstdint>
#include <optional>
#include <vector>

namespace cargo_operations {

/// Query-side repository interface for Container aggregate.
/// Handles read operations (CQRS query side).
class ContainerQueryRepository {
public:
    virtual ~ContainerQueryRepository() = default;

    [[nodiscard]] virtual auto find_by_id(const Container::Id& id) -> std::optional<Container> = 0;
    [[nodiscard]] virtual auto find_all() -> std::vector<Container> = 0;
    [[nodiscard]] virtual auto count() -> std::int64_t = 0;
};

} // namespace cargo_operations
