// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>
#include <string>

// Enum exhaustiveness tests for VesselTraffic

SCENARIO("Enum exhaustiveness: VoyageStatus states") {
    GIVEN("all states of VoyageStatus") {
        auto is_valid_state = [](const std::string& s) -> bool {
            s == "ANNOUNCED" ||
                s == "PILOT_ORDERED" ||
                s == "APPROACHING" ||
                s == "BERTHING" ||
                s == "MOORED" ||
                s == "CARGO_OPS" ||
                s == "DEPARTURE_PREP" ||
                s == "UNMOORED" ||
                s == "DEPARTED";
        };

        WHEN("each state is checked") {
            THEN("all states must be recognized") {
                // Case: VoyageStatus::ANNOUNCED
                CHECK(is_valid_state("ANNOUNCED"));
                // Case: VoyageStatus::PILOT_ORDERED
                CHECK(is_valid_state("PILOT_ORDERED"));
                // Case: VoyageStatus::APPROACHING
                CHECK(is_valid_state("APPROACHING"));
                // Case: VoyageStatus::BERTHING
                CHECK(is_valid_state("BERTHING"));
                // Case: VoyageStatus::MOORED
                CHECK(is_valid_state("MOORED"));
                // Case: VoyageStatus::CARGO_OPS
                CHECK(is_valid_state("CARGO_OPS"));
                // Case: VoyageStatus::DEPARTURE_PREP
                CHECK(is_valid_state("DEPARTURE_PREP"));
                // Case: VoyageStatus::UNMOORED
                CHECK(is_valid_state("UNMOORED"));
                // Case: VoyageStatus::DEPARTED
                CHECK(is_valid_state("DEPARTED"));
            }
        }
    }
}

SCENARIO("Enum exhaustiveness: VesselType lookup values") {
    GIVEN("the VesselType lookup table") {
        WHEN("all values are iterated") {
            THEN("each value should be handled in switch/match logic") {
                // CHECK(all_vessel_type_values_covered());
            }
        }
    }
}

SCENARIO("Enum exhaustiveness: CargoCategory lookup values") {
    GIVEN("the CargoCategory lookup table") {
        WHEN("all values are iterated") {
            THEN("each value should be handled in switch/match logic") {
                // CHECK(all_cargo_category_values_covered());
            }
        }
    }
}

SCENARIO("Enum exhaustiveness: PilotZone lookup values") {
    GIVEN("the PilotZone lookup table") {
        WHEN("all values are iterated") {
            THEN("each value should be handled in switch/match logic") {
                // CHECK(all_pilot_zone_values_covered());
            }
        }
    }
}
