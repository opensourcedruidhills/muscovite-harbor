#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "container.hpp"
#include <optional>
#include <vector>

namespace cargo_operations {

/// Repository interface for Container aggregate.
class ContainerRepository {
public:
    using Containers = std::vector<Container>;

    virtual ~ContainerRepository() = default;

    [[nodiscard]] virtual auto find_by_id(const Container::Id& id) -> std::optional<Container> = 0;
    virtual auto save(const Container& entity) -> void = 0;
    virtual auto remove(const Container::Id& id) -> void = 0;
    [[nodiscard]] virtual auto find_all() -> Containers = 0;
};

} // namespace cargo_operations
