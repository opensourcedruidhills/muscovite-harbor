// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>

// Test skeleton for ContainerDomainService
// Uses doctest BDD style (SCENARIO/GIVEN/WHEN/THEN)


SCENARIO("ContainerDomainService creates a Container") {
    GIVEN("a valid Container entity") {
        auto entity = cargo_operations::Container{};
        entity.id = "test-create-001";
        entity.id = "00000000-0000-0000-0000-000000000001";
        entity.container_number = {};
        entity.size_category = "test_value";
        entity.hazmat_class = "test_value";
        entity.voyage_id = "00000000-0000-0000-0000-000000000001";
        entity.yard_slot_id = "00000000-0000-0000-0000-000000000001";
        entity.status = "test_value";

        THEN("the entity should have its ID set") {
            CHECK(entity.id == "test-create-001");
        }
    }
}

SCENARIO("ContainerDomainService updates a Container") {
    GIVEN("an existing Container entity") {
        auto entity = cargo_operations::Container{};
        entity.id = "test-update-001";
        entity.id = "00000000-0000-0000-0000-000000000001";
        entity.container_number = {};
        entity.size_category = "test_value";
        entity.hazmat_class = "test_value";
        entity.voyage_id = "00000000-0000-0000-0000-000000000001";
        entity.yard_slot_id = "00000000-0000-0000-0000-000000000001";
        entity.status = "test_value";

        WHEN("the entity is modified") {
            entity.id = "00000000-0000-0000-0000-000000000002";
            entity.container_number = {};
            entity.size_category = "updated_value";
            entity.hazmat_class = "updated_value";
            entity.voyage_id = "00000000-0000-0000-0000-000000000002";
            entity.yard_slot_id = "00000000-0000-0000-0000-000000000002";
            entity.status = "updated_value";

            THEN("the entity should reflect the changes") {
                CHECK(entity.id == "test-update-001");
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

SCENARIO("ContainerDomainService manages Container lifecycle") {
    GIVEN("a Container entity") {
        auto entity = cargo_operations::Container{};
        entity.id = "test-lifecycle-001";

        THEN("the entity ID should be non-empty") {
            CHECK_FALSE(entity.id.empty());
        }
    }
}
