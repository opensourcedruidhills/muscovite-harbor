#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <chrono>
#include <cstdint>
#include <optional>
#include <string>
#include <vector>

namespace intermodal_transfer {

/// Step name constants for ContainerHandoff saga.
namespace container_handoff_steps {
    inline constexpr auto RESERVE_YARD_EXIT = "ReserveYardExit";
    inline constexpr auto CHECKOUT_GATE = "CheckoutGate";
    inline constexpr auto LOAD_TRANSPORT = "LoadTransport";
    inline constexpr auto CONFIRM_DEPARTURE = "ConfirmDeparture";
} // namespace container_handoff_steps

/// Correlation data for a ContainerHandoff saga instance.
struct ContainerHandoffData {
    std::string saga_id{};
    std::string payload{};
    std::string correlation_id{};
};

/// Runtime instance tracking a ContainerHandoff saga execution.
struct ContainerHandoffInstance {
    std::string id{};
    std::string status{}; // pending, in_progress, completed, failed, compensating
    std::string current_step{};
    ContainerHandoffData data{};
    std::chrono::system_clock::time_point created_at{};
    std::chrono::system_clock::time_point updated_at{};
};

/// Log entry for a single step execution within a ContainerHandoff saga.
struct ContainerHandoffStepLogEntry {
    std::string saga_id{};
    std::string step_name{};
    std::string status{}; // pending, success, failure, compensated
    std::optional<std::string> result{};
    std::optional<std::chrono::system_clock::time_point> started_at{};
    std::optional<std::chrono::system_clock::time_point> completed_at{};
};

} // namespace intermodal_transfer
