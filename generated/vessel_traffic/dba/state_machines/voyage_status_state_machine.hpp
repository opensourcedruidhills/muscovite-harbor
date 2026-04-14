#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>
#include <vector>

namespace vessel_traffic {

/// Compile-time state ID constants for VoyageStatus.
namespace voyage_status_states {
    inline constexpr auto ANNOUNCED = "ANNOUNCED";
    inline constexpr auto PILOT_ORDERED = "PILOT_ORDERED";
    inline constexpr auto APPROACHING = "APPROACHING";
    inline constexpr auto BERTHING = "BERTHING";
    inline constexpr auto MOORED = "MOORED";
    inline constexpr auto CARGO_OPS = "CARGO_OPS";
    inline constexpr auto DEPARTURE_PREP = "DEPARTURE_PREP";
    inline constexpr auto UNMOORED = "UNMOORED";
    inline constexpr auto DEPARTED = "DEPARTED";
} // namespace voyage_status_states

/// Result of a state transition attempt.
struct TransitionResult {
    bool success{false};
    std::string new_state_id{};
    std::optional<std::string> error_message{};
};

/// Describes a transition allowed from a given state.
struct AllowedTransition {
    std::string to_state{};
    std::string event_name{};
    std::optional<std::string> guard_expression{};
};

/// State machine for Voyage entity lifecycle.
class VoyageStatusStateMachine {
public:
    /// Check if a transition is allowed from current state on event.
    [[nodiscard]] auto can_transition(const std::string& current_state,
                                      const std::string& event) const -> bool;

    /// Attempt a transition; returns result with new state or error.
    [[nodiscard]] auto transition(const std::string& current_state,
                                  const std::string& event) const -> TransitionResult;

    /// List all allowed transitions from the given state.
    [[nodiscard]] auto allowed_transitions(const std::string& current_state) const -> std::vector<AllowedTransition>;

    /// Check if a state is terminal (no outgoing transitions).
    [[nodiscard]] auto is_terminal(const std::string& state) const -> bool;

    /// The initial state of this state machine.
    [[nodiscard]] auto initial_state() const -> std::string;
};

} // namespace vessel_traffic
