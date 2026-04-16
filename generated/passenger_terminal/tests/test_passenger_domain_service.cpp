// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>

// Test skeleton for PassengerDomainService
// Uses doctest BDD style (SCENARIO/GIVEN/WHEN/THEN)


SCENARIO("PassengerDomainService creates a Passenger") {
    GIVEN("a valid Passenger entity") {
        auto entity = passenger_terminal::Passenger{};
        entity.id = "test-create-001";
        entity.id = "00000000-0000-0000-0000-000000000001";
        entity.booking_ref = {};
        entity.passenger_type = "test_value";
        entity.voyage_id = "00000000-0000-0000-0000-000000000001";
        entity.status = "test_value";

        THEN("the entity should have its ID set") {
            CHECK(entity.id == "test-create-001");
        }
    }
}

SCENARIO("PassengerDomainService updates a Passenger") {
    GIVEN("an existing Passenger entity") {
        auto entity = passenger_terminal::Passenger{};
        entity.id = "test-update-001";
        entity.id = "00000000-0000-0000-0000-000000000001";
        entity.booking_ref = {};
        entity.passenger_type = "test_value";
        entity.voyage_id = "00000000-0000-0000-0000-000000000001";
        entity.status = "test_value";

        WHEN("the entity is modified") {
            entity.id = "00000000-0000-0000-0000-000000000002";
            entity.booking_ref = {};
            entity.passenger_type = "updated_value";
            entity.voyage_id = "00000000-0000-0000-0000-000000000002";
            entity.status = "updated_value";

            THEN("the entity should reflect the changes") {
                CHECK(entity.id == "test-update-001");
                CHECK(entity.id == "00000000-0000-0000-0000-000000000002");
                CHECK(entity.booking_ref == {});
                CHECK(entity.passenger_type == "updated_value");
                CHECK(entity.voyage_id == "00000000-0000-0000-0000-000000000002");
                CHECK(entity.status == "updated_value");
            }
        }
    }
}

SCENARIO("PassengerDomainService manages Passenger lifecycle") {
    GIVEN("a Passenger entity") {
        auto entity = passenger_terminal::Passenger{};
        entity.id = "test-lifecycle-001";

        THEN("the entity ID should be non-empty") {
            CHECK_FALSE(entity.id.empty());
        }
    }
}
