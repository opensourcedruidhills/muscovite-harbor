// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>

// Test skeleton for LoadPlanDomainService
// Uses doctest BDD style (SCENARIO/GIVEN/WHEN/THEN)


SCENARIO("LoadPlanDomainService creates a LoadPlan") {
    GIVEN("a valid LoadPlan entity") {
        auto entity = cargo_operations::LoadPlan{};
        entity.id = "test-create-001";
        entity.id = "00000000-0000-0000-0000-000000000001";
        entity.voyage_id = "00000000-0000-0000-0000-000000000001";
        entity.created_at = {};
        entity.status = "test_value";

        THEN("the entity should have its ID set") {
            CHECK(entity.id == "test-create-001");
        }
    }
}

SCENARIO("LoadPlanDomainService updates a LoadPlan") {
    GIVEN("an existing LoadPlan entity") {
        auto entity = cargo_operations::LoadPlan{};
        entity.id = "test-update-001";
        entity.id = "00000000-0000-0000-0000-000000000001";
        entity.voyage_id = "00000000-0000-0000-0000-000000000001";
        entity.created_at = {};
        entity.status = "test_value";

        WHEN("the entity is modified") {
            entity.id = "00000000-0000-0000-0000-000000000002";
            entity.voyage_id = "00000000-0000-0000-0000-000000000002";
            entity.created_at = {};
            entity.status = "updated_value";

            THEN("the entity should reflect the changes") {
                CHECK(entity.id == "test-update-001");
                CHECK(entity.id == "00000000-0000-0000-0000-000000000002");
                CHECK(entity.voyage_id == "00000000-0000-0000-0000-000000000002");
                CHECK(entity.created_at == {});
                CHECK(entity.status == "updated_value");
            }
        }
    }
}

SCENARIO("LoadPlanDomainService manages LoadPlan lifecycle") {
    GIVEN("a LoadPlan entity") {
        auto entity = cargo_operations::LoadPlan{};
        entity.id = "test-lifecycle-001";

        THEN("the entity ID should be non-empty") {
            CHECK_FALSE(entity.id.empty());
        }
    }
}
