// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>
#include <string>

// Enum exhaustiveness tests for CargoOperations

SCENARIO("Enum exhaustiveness: ContainerSize lookup values") {
    GIVEN("the ContainerSize lookup table") {
        WHEN("all values are iterated") {
            THEN("each value should be handled in switch/match logic") {
                // CHECK(all_container_size_values_covered());
            }
        }
    }
}

SCENARIO("Enum exhaustiveness: HazmatClass lookup values") {
    GIVEN("the HazmatClass lookup table") {
        WHEN("all values are iterated") {
            THEN("each value should be handled in switch/match logic") {
                // CHECK(all_hazmat_class_values_covered());
            }
        }
    }
}
