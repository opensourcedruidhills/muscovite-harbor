#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "load_plan.hpp"
#include "load_plan_query_repository.hpp"
#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace cargo_operations {

/// Query service for LoadPlan aggregate.
/// Handles all read operations (CQRS query side).
class LoadPlanQueryService {
public:
    explicit LoadPlanQueryService(LoadPlanQueryRepository& repository)
        : repository_{repository} {}

    [[nodiscard]] auto find_by_id(const LoadPlan::Id& id) -> std::optional<LoadPlan>;
    [[nodiscard]] auto find_all() -> std::vector<LoadPlan>;
    [[nodiscard]] auto count() -> std::int64_t;

private:
    LoadPlanQueryRepository& repository_;
};

} // namespace cargo_operations
