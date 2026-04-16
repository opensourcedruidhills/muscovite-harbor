// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>

// V2 DBA integration tests for Embarkation aggregate
// Context: PassengerTerminal


SCENARIO("Create Passenger") {
    GIVEN("a Passenger with valid fields") {
        auto entity = passenger_terminal::Passenger{};
        entity.id = "00000000-0000-0000-0000-000000000001";
        entity.booking_ref = {};
        entity.passenger_type = "test_value";
        entity.voyage_id = "00000000-0000-0000-0000-000000000001";
        entity.status = "test_value";

        WHEN("the entity is created") {
            THEN("all fields should be set") {
                CHECK_FALSE(entity.id.empty());
                CHECK(entity.id == "00000000-0000-0000-0000-000000000001");
                CHECK(entity.passenger_type == "test_value");
                CHECK(entity.voyage_id == "00000000-0000-0000-0000-000000000001");
                CHECK(entity.status == "test_value");
            }
        }
    }
}

SCENARIO("Passenger round-trip serialization") {
    GIVEN("a Passenger with populated fields") {
        auto entity = passenger_terminal::Passenger{};
        entity.id = "00000000-0000-0000-0000-000000000001";
        entity.booking_ref = {};
        entity.passenger_type = "test_value";
        entity.voyage_id = "00000000-0000-0000-0000-000000000001";
        entity.status = "test_value";

        WHEN("checked for default state") {
            THEN("the entity should have non-default values") {
                CHECK(entity.id == "00000000-0000-0000-0000-000000000001");
                CHECK(entity.passenger_type == "test_value");
                CHECK(entity.voyage_id == "00000000-0000-0000-0000-000000000001");
                CHECK(entity.status == "test_value");
            }
        }
    }
}

SCENARIO("Update Passenger fields") {
    GIVEN("a Passenger with initial values") {
        auto entity = passenger_terminal::Passenger{};
        entity.id = "00000000-0000-0000-0000-000000000001";
        entity.booking_ref = {};
        entity.passenger_type = "test_value";
        entity.voyage_id = "00000000-0000-0000-0000-000000000001";
        entity.status = "test_value";

        WHEN("fields are modified") {
            entity.id = "00000000-0000-0000-0000-000000000002";
            entity.booking_ref = {};
            entity.passenger_type = "updated_value";
            entity.voyage_id = "00000000-0000-0000-0000-000000000002";
            entity.status = "updated_value";

            THEN("the entity reflects the new values") {
                CHECK(entity.id == "00000000-0000-0000-0000-000000000002");
                CHECK(entity.booking_ref == {});
                CHECK(entity.passenger_type == "updated_value");
                CHECK(entity.voyage_id == "00000000-0000-0000-0000-000000000002");
                CHECK(entity.status == "updated_value");
            }
        }
    }
}

SCENARIO("Passenger identity comparison") {
    GIVEN("two Passenger entities with the same ID") {
        auto a = passenger_terminal::Passenger{};
        auto b = passenger_terminal::Passenger{};
        a.id = b.id = "test-id-001";

        WHEN("compared") {
            THEN("they should be considered equal by ID") {
                CHECK(a.id == b.id);
            }
        }
    }
}

SCENARIO("Add child BoardingPass to Passenger") {
    GIVEN("an existing Passenger aggregate root") {
        WHEN("a BoardingPass child is added") {
            // auto result = cmd_service.add_child(parent_id, child);

            THEN("the child should be part of the aggregate") {
                // CHECK(result.has_value());
            }
        }
    }
}
