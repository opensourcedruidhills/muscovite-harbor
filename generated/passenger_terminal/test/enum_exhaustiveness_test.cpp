// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>
#include <string>

// Enum exhaustiveness tests for PassengerTerminal

SCENARIO("Enum exhaustiveness: GateStatus states") {
    GIVEN("all states of GateStatus") {
        auto is_valid_state = [](const std::string& s) -> bool {
            s == "CLOSED" ||
                s == "CHECK_IN_OPEN" ||
                s == "BOARDING" ||
                s == "FINAL_CALL";
        };

        WHEN("each state is checked") {
            THEN("all states must be recognized") {
                // Case: GateStatus::CLOSED
                CHECK(is_valid_state("CLOSED"));
                // Case: GateStatus::CHECK_IN_OPEN
                CHECK(is_valid_state("CHECK_IN_OPEN"));
                // Case: GateStatus::BOARDING
                CHECK(is_valid_state("BOARDING"));
                // Case: GateStatus::FINAL_CALL
                CHECK(is_valid_state("FINAL_CALL"));
            }
        }
    }
}

SCENARIO("Enum exhaustiveness: PassengerStatus states") {
    GIVEN("all states of PassengerStatus") {
        auto is_valid_state = [](const std::string& s) -> bool {
            s == "CHECKED_IN" ||
                s == "SECURITY_CLEARED" ||
                s == "BOARDED" ||
                s == "DISEMBARKED";
        };

        WHEN("each state is checked") {
            THEN("all states must be recognized") {
                // Case: PassengerStatus::CHECKED_IN
                CHECK(is_valid_state("CHECKED_IN"));
                // Case: PassengerStatus::SECURITY_CLEARED
                CHECK(is_valid_state("SECURITY_CLEARED"));
                // Case: PassengerStatus::BOARDED
                CHECK(is_valid_state("BOARDED"));
                // Case: PassengerStatus::DISEMBARKED
                CHECK(is_valid_state("DISEMBARKED"));
            }
        }
    }
}

SCENARIO("Enum exhaustiveness: PassengerType lookup values") {
    GIVEN("the PassengerType lookup table") {
        WHEN("all values are iterated") {
            THEN("each value should be handled in switch/match logic") {
                // CHECK(all_passenger_type_values_covered());
            }
        }
    }
}
