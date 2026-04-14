#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "load_plan.hpp"
#include "load_plan_command_service.hpp"
#include "load_plan_query_service.hpp"
#include "discharge_sequence.hpp"
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace cargo_operations {

/// Domain service for LoadPlan aggregate.
/// Orchestrates three-tier validation pipeline and delegates to
/// CommandService (writes) and QueryService (reads).
class LoadPlanDomainService {
public:
    explicit LoadPlanDomainService(LoadPlanCommandService& command_service, LoadPlanQueryService& query_service)
        : command_service_{command_service}
        , query_service_{query_service} {}

    // Command operations (write side)
    auto create(const LoadPlan& entity) -> void;
    auto update(const LoadPlan& entity) -> void;
    auto remove(const LoadPlan::Id& id) -> void;

    // Query operations (read side — pass-through)
    [[nodiscard]] auto find_by_id(const LoadPlan::Id& id) -> std::optional<LoadPlan>;
    [[nodiscard]] auto find_all() -> std::vector<LoadPlan>;

    // DischargeSequence child entity operations
    auto add_discharge_sequence(const LoadPlan::Id& parent_id, const DischargeSequence& child) -> void;
    auto remove_discharge_sequence(const LoadPlan::Id& parent_id, const DischargeSequence::Id& child_id) -> void;

private:
    LoadPlanCommandService& command_service_;
    LoadPlanQueryService& query_service_;
};

} // namespace cargo_operations
