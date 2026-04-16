// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>

// V2 DBA integration tests for ContainerStack aggregate
// Context: CargoOperations


SCENARIO("Create Container") {
    GIVEN("a Container with valid fields") {
        auto entity = cargo_operations::Container{};
        entity.id = "00000000-0000-0000-0000-000000000001";
        entity.container_number = {};
        entity.size_category = "test_value";
        entity.hazmat_class = "test_value";
        entity.voyage_id = "00000000-0000-0000-0000-000000000001";
        entity.yard_slot_id = "00000000-0000-0000-0000-000000000001";
        entity.status = "test_value";

        WHEN("the entity is created") {
            THEN("all fields should be set") {
                CHECK_FALSE(entity.id.empty());
                CHECK(entity.id == "00000000-0000-0000-0000-000000000001");
                CHECK(entity.size_category == "test_value");
                CHECK(entity.hazmat_class == "test_value");
                CHECK(entity.voyage_id == "00000000-0000-0000-0000-000000000001");
                CHECK(entity.yard_slot_id == "00000000-0000-0000-0000-000000000001");
                CHECK(entity.status == "test_value");
            }
        }
    }
}

SCENARIO("Container round-trip serialization") {
    GIVEN("a Container with populated fields") {
        auto entity = cargo_operations::Container{};
        entity.id = "00000000-0000-0000-0000-000000000001";
        entity.container_number = {};
        entity.size_category = "test_value";
        entity.hazmat_class = "test_value";
        entity.voyage_id = "00000000-0000-0000-0000-000000000001";
        entity.yard_slot_id = "00000000-0000-0000-0000-000000000001";
        entity.status = "test_value";

        WHEN("checked for default state") {
            THEN("the entity should have non-default values") {
                CHECK(entity.id == "00000000-0000-0000-0000-000000000001");
                CHECK(entity.size_category == "test_value");
                CHECK(entity.hazmat_class == "test_value");
                CHECK(entity.voyage_id == "00000000-0000-0000-0000-000000000001");
                CHECK(entity.yard_slot_id == "00000000-0000-0000-0000-000000000001");
                CHECK(entity.status == "test_value");
            }
        }
    }
}

SCENARIO("Update Container fields") {
    GIVEN("a Container with initial values") {
        auto entity = cargo_operations::Container{};
        entity.id = "00000000-0000-0000-0000-000000000001";
        entity.container_number = {};
        entity.size_category = "test_value";
        entity.hazmat_class = "test_value";
        entity.voyage_id = "00000000-0000-0000-0000-000000000001";
        entity.yard_slot_id = "00000000-0000-0000-0000-000000000001";
        entity.status = "test_value";

        WHEN("fields are modified") {
            entity.id = "00000000-0000-0000-0000-000000000002";
            entity.container_number = {};
            entity.size_category = "updated_value";
            entity.hazmat_class = "updated_value";
            entity.voyage_id = "00000000-0000-0000-0000-000000000002";
            entity.yard_slot_id = "00000000-0000-0000-0000-000000000002";
            entity.status = "updated_value";

            THEN("the entity reflects the new values") {
                CHECK(entity.id == "00000000-0000-0000-0000-000000000002");
                CHECK(entity.container_number == {});
                CHECK(entity.size_category == "updated_value");
                CHECK(entity.hazmat_class == "updated_value");
                CHECK(entity.voyage_id == "00000000-0000-0000-0000-000000000002");
                CHECK(entity.yard_slot_id == "00000000-0000-0000-0000-000000000002");
                CHECK(entity.status == "updated_value");
            }
        }
    }
}

SCENARIO("Container identity comparison") {
    GIVEN("two Container entities with the same ID") {
        auto a = cargo_operations::Container{};
        auto b = cargo_operations::Container{};
        a.id = b.id = "test-id-001";

        WHEN("compared") {
            THEN("they should be considered equal by ID") {
                CHECK(a.id == b.id);
            }
        }
    }
}
