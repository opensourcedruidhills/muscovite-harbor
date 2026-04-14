#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "load_plan.hpp"
#include <optional>
#include <vector>

namespace cargo_operations {

/// Repository interface for LoadPlan aggregate.
class LoadPlanRepository {
public:
    using LoadPlans = std::vector<LoadPlan>;

    virtual ~LoadPlanRepository() = default;

    [[nodiscard]] virtual auto find_by_id(const LoadPlan::Id& id) -> std::optional<LoadPlan> = 0;
    virtual auto save(const LoadPlan& entity) -> void = 0;
    virtual auto remove(const LoadPlan::Id& id) -> void = 0;
    [[nodiscard]] virtual auto find_all() -> LoadPlans = 0;
};

} // namespace cargo_operations
