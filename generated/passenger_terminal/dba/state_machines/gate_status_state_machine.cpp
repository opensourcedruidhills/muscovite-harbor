// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "gate_status_state_machine.hpp"

namespace passenger_terminal {

auto GateStatusStateMachine::can_transition(const std::string& current_state,
                                  const std::string& event) const -> bool {
    if (current_state == "CLOSED" && event == "OpenCheckIn") {
        return true;
    } else if (current_state == "CHECK_IN_OPEN" && event == "StartBoarding") {
        return true;
    } else if (current_state == "BOARDING" && event == "AnnounceFinalCall") {
        return true;
    } else if (current_state == "FINAL_CALL" && event == "CloseGate") {
        return true;
    } else if (current_state == "CHECK_IN_OPEN" && event == "CancelBoarding") {
        return true;
    }
    return false;
}

auto GateStatusStateMachine::transition(const std::string& current_state,
                              const std::string& event) const -> TransitionResult {
    if (current_state == "CLOSED" && event == "OpenCheckIn") {
        return TransitionResult{.success = true, .new_state_id = "CHECK_IN_OPEN"};
    } else if (current_state == "CHECK_IN_OPEN" && event == "StartBoarding") {
        return TransitionResult{.success = true, .new_state_id = "BOARDING"};
    } else if (current_state == "BOARDING" && event == "AnnounceFinalCall") {
        return TransitionResult{.success = true, .new_state_id = "FINAL_CALL"};
    } else if (current_state == "FINAL_CALL" && event == "CloseGate") {
        return TransitionResult{.success = true, .new_state_id = "CLOSED"};
    } else if (current_state == "CHECK_IN_OPEN" && event == "CancelBoarding") {
        return TransitionResult{.success = true, .new_state_id = "CLOSED"};
    }
    return TransitionResult{.success = false, .error_message = "No valid transition from '" + current_state + "' on event '" + event + "'"};
}

auto GateStatusStateMachine::allowed_transitions(const std::string& current_state) const -> std::vector<AllowedTransition> {
    auto result = std::vector<AllowedTransition>{};
    if (current_state == "CLOSED") {
        result.push_back(AllowedTransition{.to_state = "CHECK_IN_OPEN", .event_name = "OpenCheckIn"});
    }
    if (current_state == "CHECK_IN_OPEN") {
        result.push_back(AllowedTransition{.to_state = "BOARDING", .event_name = "StartBoarding"});
    }
    if (current_state == "BOARDING") {
        result.push_back(AllowedTransition{.to_state = "FINAL_CALL", .event_name = "AnnounceFinalCall"});
    }
    if (current_state == "FINAL_CALL") {
        result.push_back(AllowedTransition{.to_state = "CLOSED", .event_name = "CloseGate"});
    }
    if (current_state == "CHECK_IN_OPEN") {
        result.push_back(AllowedTransition{.to_state = "CLOSED", .event_name = "CancelBoarding"});
    }
    return result;
}

auto GateStatusStateMachine::is_terminal(const std::string& state) const -> bool {
    if (state == "CLOSED") {
        return true;
    }
    return false;
}

auto GateStatusStateMachine::initial_state() const -> std::string {
    return "CLOSED";
}

} // namespace passenger_terminal
