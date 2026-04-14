// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "load_plan_query_service.hpp"

namespace cargo_operations {

auto LoadPlanQueryService::find_by_id(const LoadPlan::Id& id) -> std::optional<LoadPlan> {
    return repository_.find_by_id(id);
}

auto LoadPlanQueryService::find_all() -> std::vector<LoadPlan> {
    return repository_.find_all();
}

auto LoadPlanQueryService::count() -> std::int64_t {
    return repository_.count();
}

} // namespace cargo_operations
