// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "load_plan_command_service.hpp"

namespace cargo_operations {

auto LoadPlanCommandService::create(const LoadPlan& entity) -> void {
    repository_.save(entity);
}

auto LoadPlanCommandService::update(const LoadPlan& entity) -> void {
    repository_.save(entity);
}

auto LoadPlanCommandService::remove(const LoadPlan::Id& id) -> void {
    repository_.remove(id);
}

} // namespace cargo_operations
