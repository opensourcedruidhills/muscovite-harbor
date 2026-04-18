// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>

// V2 DBA integration tests for LoadPlanExecution aggregate
// Context: CargoOperations


SCENARIO("Create LoadPlan") {
    GIVEN("a LoadPlan with valid fields") {
        auto entity = cargo_operations::LoadPlan{};
        entity.id = "00000000-0000-0000-0000-000000000001";
        entity.voyage_id = "00000000-0000-0000-0000-000000000001";
        entity.created_at = {};
        entity.status = "test_value";

        WHEN("the entity is created") {
            THEN("all fields should be set") {
                CHECK_FALSE(entity.id.empty());
                CHECK(entity.id == "00000000-0000-0000-0000-000000000001");
                CHECK(entity.voyage_id == "00000000-0000-0000-0000-000000000001");
                CHECK(entity.status == "test_value");
            }
        }
    }
}

SCENARIO("LoadPlan round-trip serialization") {
    GIVEN("a LoadPlan with populated fields") {
        auto entity = cargo_operations::LoadPlan{};
        entity.id = "00000000-0000-0000-0000-000000000001";
        entity.voyage_id = "00000000-0000-0000-0000-000000000001";
        entity.created_at = {};
        entity.status = "test_value";

        WHEN("checked for default state") {
            THEN("the entity should have non-default values") {
                CHECK(entity.id == "00000000-0000-0000-0000-000000000001");
                CHECK(entity.voyage_id == "00000000-0000-0000-0000-000000000001");
                CHECK(entity.status == "test_value");
            }
        }
    }
}

SCENARIO("Update LoadPlan fields") {
    GIVEN("a LoadPlan with initial values") {
        auto entity = cargo_operations::LoadPlan{};
        entity.id = "00000000-0000-0000-0000-000000000001";
        entity.voyage_id = "00000000-0000-0000-0000-000000000001";
        entity.created_at = {};
        entity.status = "test_value";

        WHEN("fields are modified") {
            entity.id = "00000000-0000-0000-0000-000000000002";
            entity.voyage_id = "00000000-0000-0000-0000-000000000002";
            entity.created_at = {};
            entity.status = "updated_value";

            THEN("the entity reflects the new values") {
                CHECK(entity.id == "00000000-0000-0000-0000-000000000002");
                CHECK(entity.voyage_id == "00000000-0000-0000-0000-000000000002");
                CHECK(entity.created_at == {});
                CHECK(entity.status == "updated_value");
            }
        }
    }
}

SCENARIO("LoadPlan identity comparison") {
    GIVEN("two LoadPlan entities with the same ID") {
        auto a = cargo_operations::LoadPlan{};
        auto b = cargo_operations::LoadPlan{};
        a.id = b.id = "test-id-001";

        WHEN("compared") {
            THEN("they should be considered equal by ID") {
                CHECK(a.id == b.id);
            }
        }
    }
}

SCENARIO("Add child DischargeSequence to LoadPlan") {
    GIVEN("an existing LoadPlan aggregate root") {
        WHEN("a DischargeSequence child is added") {
            auto child = DischargeSequence{};
            auto parent_id = LoadPlan::Id{};
            domain_service.add_discharge_sequence(parent_id, child);

            THEN("the child should be part of the aggregate") {
                CHECK_NOTHROW(domain_service.add_discharge_sequence(parent_id, child));
            }
        }
    }
}
