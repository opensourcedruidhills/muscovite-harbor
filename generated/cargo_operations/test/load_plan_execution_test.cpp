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

        WHEN("the entity is created via command service") {
            // auto result = cmd_service.create(entity);

            THEN("it should be persisted successfully") {
                // CHECK(result.has_value());
            }
        }
    }
}

SCENARIO("Find LoadPlan by ID") {
    GIVEN("an existing LoadPlan") {
        WHEN("queried by its ID") {
            // auto found = query_service.find_by_id(id);

            THEN("the entity should be returned") {
                // CHECK(found.has_value());
            }
        }
    }
}

SCENARIO("Find all LoadPlan") {
    GIVEN("multiple LoadPlan entities exist") {
        WHEN("all are queried") {
            // auto all = query_service.find_all();

            THEN("all entities should be returned") {
                // CHECK(!all.empty());
            }
        }
    }
}

SCENARIO("Update LoadPlan") {
    GIVEN("an existing LoadPlan") {
        WHEN("a field is modified and saved") {
            // auto updated = cmd_service.update(entity);

            THEN("the change should be persisted") {
                // CHECK(updated.has_value());
            }
        }
    }
}

SCENARIO("Remove LoadPlan") {
    GIVEN("an existing LoadPlan") {
        WHEN("the entity is removed") {
            // cmd_service.remove(id);

            THEN("it should no longer be findable") {
                // auto found = query_service.find_by_id(id);
                // CHECK(!found.has_value());
            }
        }
    }
}

SCENARIO("Add child DischargeSequence to LoadPlan") {
    GIVEN("an existing LoadPlan aggregate root") {
        WHEN("a DischargeSequence child is added") {
            // auto result = cmd_service.add_child(parent_id, child);

            THEN("the child should be part of the aggregate") {
                // CHECK(result.has_value());
            }
        }
    }
}
