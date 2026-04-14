// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>

// V2 DBA integration tests for IntermodalHandoff aggregate
// Context: IntermodalTransfer


SCENARIO("Create TransferSlot") {
    GIVEN("a TransferSlot with valid fields") {
        auto entity = intermodal_transfer::TransferSlot{};
        entity.id = "00000000-0000-0000-0000-000000000001";
        entity.reference = {};
        entity.container_id = "00000000-0000-0000-0000-000000000001";
        entity.transport_mode = "test_value";
        entity.scheduled_at = {};
        entity.status = "test_value";

        WHEN("the entity is created via command service") {
            // auto result = cmd_service.create(entity);

            THEN("it should be persisted successfully") {
                // CHECK(result.has_value());
            }
        }
    }
}

SCENARIO("Find TransferSlot by ID") {
    GIVEN("an existing TransferSlot") {
        WHEN("queried by its ID") {
            // auto found = query_service.find_by_id(id);

            THEN("the entity should be returned") {
                // CHECK(found.has_value());
            }
        }
    }
}

SCENARIO("Find all TransferSlot") {
    GIVEN("multiple TransferSlot entities exist") {
        WHEN("all are queried") {
            // auto all = query_service.find_all();

            THEN("all entities should be returned") {
                // CHECK(!all.empty());
            }
        }
    }
}

SCENARIO("Update TransferSlot") {
    GIVEN("an existing TransferSlot") {
        WHEN("a field is modified and saved") {
            // auto updated = cmd_service.update(entity);

            THEN("the change should be persisted") {
                // CHECK(updated.has_value());
            }
        }
    }
}

SCENARIO("Remove TransferSlot") {
    GIVEN("an existing TransferSlot") {
        WHEN("the entity is removed") {
            // cmd_service.remove(id);

            THEN("it should no longer be findable") {
                // auto found = query_service.find_by_id(id);
                // CHECK(!found.has_value());
            }
        }
    }
}

SCENARIO("Add child TruckVisit to TransferSlot") {
    GIVEN("an existing TransferSlot aggregate root") {
        WHEN("a TruckVisit child is added") {
            // auto result = cmd_service.add_child(parent_id, child);

            THEN("the child should be part of the aggregate") {
                // CHECK(result.has_value());
            }
        }
    }
}
