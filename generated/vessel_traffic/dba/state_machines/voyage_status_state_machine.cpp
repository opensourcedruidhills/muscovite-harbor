// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "voyage_status_state_machine.hpp"

namespace vessel_traffic {

auto VoyageStatusStateMachine::can_transition(const std::string& current_state,
                                  const std::string& event) const -> bool {
    if (current_state == "ANNOUNCED" && event == "OrderPilot") {
        return true;
    } else if (current_state == "PILOT_ORDERED" && event == "VesselApproaching") {
        return true;
    } else if (current_state == "APPROACHING" && event == "BeginBerthing") {
        if (tide_window_open) {
            return true;
        }
    } else if (current_state == "BERTHING" && event == "VesselMoored") {
        return true;
    } else if (current_state == "MOORED" && event == "BeginCargoOps") {
        return true;
    } else if (current_state == "CARGO_OPS" && event == "CargoComplete") {
        return true;
    } else if (current_state == "DEPARTURE_PREP" && event == "CastOff") {
        if (departure_clearance) {
            return true;
        }
    } else if (current_state == "UNMOORED" && event == "VesselDeparted") {
        return true;
    } else if (current_state == "APPROACHING" && event == "AbortApproach") {
        return true;
    } else if (current_state == "BERTHING" && event == "AbortBerthing") {
        return true;
    }
    return false;
}

auto VoyageStatusStateMachine::transition(const std::string& current_state,
                              const std::string& event) const -> TransitionResult {
    if (current_state == "ANNOUNCED" && event == "OrderPilot") {
        return TransitionResult{.success = true, .new_state_id = "PILOT_ORDERED"};
    } else if (current_state == "PILOT_ORDERED" && event == "VesselApproaching") {
        return TransitionResult{.success = true, .new_state_id = "APPROACHING"};
    } else if (current_state == "APPROACHING" && event == "BeginBerthing") {
        if (tide_window_open) {
            return TransitionResult{.success = true, .new_state_id = "BERTHING"};
        }
    } else if (current_state == "BERTHING" && event == "VesselMoored") {
        return TransitionResult{.success = true, .new_state_id = "MOORED"};
    } else if (current_state == "MOORED" && event == "BeginCargoOps") {
        return TransitionResult{.success = true, .new_state_id = "CARGO_OPS"};
    } else if (current_state == "CARGO_OPS" && event == "CargoComplete") {
        return TransitionResult{.success = true, .new_state_id = "DEPARTURE_PREP"};
    } else if (current_state == "DEPARTURE_PREP" && event == "CastOff") {
        if (departure_clearance) {
            return TransitionResult{.success = true, .new_state_id = "UNMOORED"};
        }
    } else if (current_state == "UNMOORED" && event == "VesselDeparted") {
        return TransitionResult{.success = true, .new_state_id = "DEPARTED"};
    } else if (current_state == "APPROACHING" && event == "AbortApproach") {
        return TransitionResult{.success = true, .new_state_id = "ANNOUNCED"};
    } else if (current_state == "BERTHING" && event == "AbortBerthing") {
        return TransitionResult{.success = true, .new_state_id = "APPROACHING"};
    }
    return TransitionResult{.success = false, .error_message = "No valid transition from '" + current_state + "' on event '" + event + "'"};
}

auto VoyageStatusStateMachine::allowed_transitions(const std::string& current_state) const -> std::vector<AllowedTransition> {
    auto result = std::vector<AllowedTransition>{};
    if (current_state == "ANNOUNCED") {
        result.push_back(AllowedTransition{.to_state = "PILOT_ORDERED", .event_name = "OrderPilot", .guard_expression = std::nullopt});
    }
    if (current_state == "PILOT_ORDERED") {
        result.push_back(AllowedTransition{.to_state = "APPROACHING", .event_name = "VesselApproaching", .guard_expression = std::nullopt});
    }
    if (current_state == "APPROACHING") {
        result.push_back(AllowedTransition{.to_state = "BERTHING", .event_name = "BeginBerthing", .guard_expression = "tide_window_open"});
    }
    if (current_state == "BERTHING") {
        result.push_back(AllowedTransition{.to_state = "MOORED", .event_name = "VesselMoored", .guard_expression = std::nullopt});
    }
    if (current_state == "MOORED") {
        result.push_back(AllowedTransition{.to_state = "CARGO_OPS", .event_name = "BeginCargoOps", .guard_expression = std::nullopt});
    }
    if (current_state == "CARGO_OPS") {
        result.push_back(AllowedTransition{.to_state = "DEPARTURE_PREP", .event_name = "CargoComplete", .guard_expression = std::nullopt});
    }
    if (current_state == "DEPARTURE_PREP") {
        result.push_back(AllowedTransition{.to_state = "UNMOORED", .event_name = "CastOff", .guard_expression = "departure_clearance"});
    }
    if (current_state == "UNMOORED") {
        result.push_back(AllowedTransition{.to_state = "DEPARTED", .event_name = "VesselDeparted", .guard_expression = std::nullopt});
    }
    if (current_state == "APPROACHING") {
        result.push_back(AllowedTransition{.to_state = "ANNOUNCED", .event_name = "AbortApproach", .guard_expression = std::nullopt});
    }
    if (current_state == "BERTHING") {
        result.push_back(AllowedTransition{.to_state = "APPROACHING", .event_name = "AbortBerthing", .guard_expression = std::nullopt});
    }
    return result;
}

auto VoyageStatusStateMachine::is_terminal(const std::string& state) const -> bool {
    if (state == "DEPARTED") {
        return true;
    }
    return false;
}

auto VoyageStatusStateMachine::initial_state() const -> std::string {
    return "ANNOUNCED";
}

} // namespace vessel_traffic
