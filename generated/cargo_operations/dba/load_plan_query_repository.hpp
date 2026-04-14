#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "load_plan.hpp"
#include <cstdint>
#include <optional>
#include <vector>

namespace cargo_operations {

/// Query-side repository interface for LoadPlan aggregate.
/// Handles read operations (CQRS query side).
class LoadPlanQueryRepository {
public:
    virtual ~LoadPlanQueryRepository() = default;

    [[nodiscard]] virtual auto find_by_id(const LoadPlan::Id& id) -> std::optional<LoadPlan> = 0;
    [[nodiscard]] virtual auto find_all() -> std::vector<LoadPlan> = 0;
    [[nodiscard]] virtual auto count() -> std::int64_t = 0;
};

} // namespace cargo_operations
