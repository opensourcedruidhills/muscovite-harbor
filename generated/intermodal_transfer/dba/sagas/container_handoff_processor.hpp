#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "container_handoff_structs.hpp"
#include "container_handoff_repository.hpp"
#include <memory>
#include <string>

namespace intermodal_transfer {

/// 4-step container handoff saga with full compensation
/// Orchestrator for the ContainerHandoff saga.
/// Triggered by: YardExitReserved
class ContainerHandoffProcessor {
public:
    ContainerHandoffProcessor(ContainerHandoffCommandRepository& cmd_repo,
        ContainerHandoffQueryRepository& query_repo)
        : cmd_repo_{cmd_repo}, query_repo_{query_repo} {}

    virtual ~ContainerHandoffProcessor() = default;

    /// Start a new saga instance.
    auto start(const ContainerHandoffData& data) -> std::string;

    /// Execute the next step for the given saga instance.
    auto execute_step(const std::string& saga_id) -> bool;

    /// Run compensation in reverse order for a failed saga.
    auto run_compensation(const std::string& saga_id) -> void;

    /// Check for timed-out saga instances.
    auto check_timeouts(std::chrono::seconds threshold) -> void;

    // Per-step handlers (implement in derived class)
    [[nodiscard]] virtual auto handle_reserve_yard_exit(const ContainerHandoffInstance& instance) -> bool = 0;
    [[nodiscard]] virtual auto handle_checkout_gate(const ContainerHandoffInstance& instance) -> bool = 0;
    [[nodiscard]] virtual auto handle_load_transport(const ContainerHandoffInstance& instance) -> bool = 0;
    [[nodiscard]] virtual auto handle_confirm_departure(const ContainerHandoffInstance& instance) -> bool = 0;

protected:
    ContainerHandoffCommandRepository& cmd_repo_;
    ContainerHandoffQueryRepository& query_repo_;
};

} // namespace intermodal_transfer
