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

        WHEN("the entity is created via command service") {
            // auto result = cmd_service.create(entity);

            THEN("it should be persisted successfully") {
                // CHECK(result.has_value());
            }
        }
    }
}

SCENARIO("Find Container by ID") {
    GIVEN("an existing Container") {
        WHEN("queried by its ID") {
            // auto found = query_service.find_by_id(id);

            THEN("the entity should be returned") {
                // CHECK(found.has_value());
            }
        }
    }
}

SCENARIO("Find all Container") {
    GIVEN("multiple Container entities exist") {
        WHEN("all are queried") {
            // auto all = query_service.find_all();

            THEN("all entities should be returned") {
                // CHECK(!all.empty());
            }
        }
    }
}

SCENARIO("Update Container") {
    GIVEN("an existing Container") {
        WHEN("a field is modified and saved") {
            // auto updated = cmd_service.update(entity);

            THEN("the change should be persisted") {
                // CHECK(updated.has_value());
            }
        }
    }
}

SCENARIO("Remove Container") {
    GIVEN("an existing Container") {
        WHEN("the entity is removed") {
            // cmd_service.remove(id);

            THEN("it should no longer be findable") {
                // auto found = query_service.find_by_id(id);
                // CHECK(!found.has_value());
            }
        }
    }
}
