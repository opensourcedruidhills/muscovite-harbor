#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "load_plan.hpp"
#include "load_plan_command_repository.hpp"
#include <memory>
#include <string>

namespace cargo_operations {

/// Command service for LoadPlan aggregate.
/// Handles all write operations (CQRS command side).
class LoadPlanCommandService {
public:
    explicit LoadPlanCommandService(LoadPlanCommandRepository& repository)
        : repository_{repository} {}

    auto create(const LoadPlan& entity) -> void;
    auto update(const LoadPlan& entity) -> void;
    auto remove(const LoadPlan::Id& id) -> void;

private:
    LoadPlanCommandRepository& repository_;
};

} // namespace cargo_operations
