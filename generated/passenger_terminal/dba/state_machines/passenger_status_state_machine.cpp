// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "passenger_status_state_machine.hpp"

namespace passenger_terminal {

auto PassengerStatusStateMachine::can_transition(const std::string& current_state,
                                  const std::string& event) const -> bool {
    if (current_state == "CHECKED_IN" && event == "PassSecurity") {
        return true;
    } else if (current_state == "SECURITY_CLEARED" && event == "BoardVessel") {
        return true;
    } else if (current_state == "BOARDED" && event == "Disembark") {
        return true;
    }
    return false;
}

auto PassengerStatusStateMachine::transition(const std::string& current_state,
                              const std::string& event) const -> TransitionResult {
    if (current_state == "CHECKED_IN" && event == "PassSecurity") {
        return TransitionResult{.success = true, .new_state_id = "SECURITY_CLEARED"};
    } else if (current_state == "SECURITY_CLEARED" && event == "BoardVessel") {
        return TransitionResult{.success = true, .new_state_id = "BOARDED"};
    } else if (current_state == "BOARDED" && event == "Disembark") {
        return TransitionResult{.success = true, .new_state_id = "DISEMBARKED"};
    }
    return TransitionResult{.success = false, .error_message = "No valid transition from '" + current_state + "' on event '" + event + "'"};
}

auto PassengerStatusStateMachine::allowed_transitions(const std::string& current_state) const -> std::vector<AllowedTransition> {
    auto result = std::vector<AllowedTransition>{};
    if (current_state == "CHECKED_IN") {
        result.push_back(AllowedTransition{.to_state = "SECURITY_CLEARED", .event_name = "PassSecurity"});
    }
    if (current_state == "SECURITY_CLEARED") {
        result.push_back(AllowedTransition{.to_state = "BOARDED", .event_name = "BoardVessel"});
    }
    if (current_state == "BOARDED") {
        result.push_back(AllowedTransition{.to_state = "DISEMBARKED", .event_name = "Disembark"});
    }
    return result;
}

auto PassengerStatusStateMachine::is_terminal(const std::string& state) const -> bool {
    if (state == "DISEMBARKED") {
        return true;
    }
    return false;
}

auto PassengerStatusStateMachine::initial_state() const -> std::string {
    return "CHECKED_IN";
}

} // namespace passenger_terminal
