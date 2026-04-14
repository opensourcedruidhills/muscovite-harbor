#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "load_plan.hpp"
#include <optional>
#include <string>
#include <vector>

namespace cargo_operations {

/// Command-side repository interface for LoadPlan aggregate.
/// Handles write operations (create, update, delete).
class LoadPlanCommandRepository {
public:
    virtual ~LoadPlanCommandRepository() = default;

    virtual auto save(const LoadPlan& entity) -> void = 0;
    virtual auto remove(const LoadPlan::Id& id) -> void = 0;
    [[nodiscard]] virtual auto find_by_id(const LoadPlan::Id& id) -> std::optional<LoadPlan> = 0;
};

} // namespace cargo_operations
