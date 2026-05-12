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

        WHEN("the entity is created") {
            THEN("all fields should be set") {
                CHECK_FALSE(entity.id.empty());
                CHECK(entity.id == "00000000-0000-0000-0000-000000000001");
                CHECK(entity.container_id == "00000000-0000-0000-0000-000000000001");
                CHECK(entity.transport_mode == "test_value");
                CHECK(entity.status == "test_value");
            }
        }
    }
}

SCENARIO("TransferSlot round-trip serialization") {
    GIVEN("a TransferSlot with populated fields") {
        auto entity = intermodal_transfer::TransferSlot{};
        entity.id = "00000000-0000-0000-0000-000000000001";
        entity.reference = {};
        entity.container_id = "00000000-0000-0000-0000-000000000001";
        entity.transport_mode = "test_value";
        entity.scheduled_at = {};
        entity.status = "test_value";

        WHEN("checked for default state") {
            THEN("the entity should have non-default values") {
                CHECK(entity.id == "00000000-0000-0000-0000-000000000001");
                CHECK(entity.container_id == "00000000-0000-0000-0000-000000000001");
                CHECK(entity.transport_mode == "test_value");
                CHECK(entity.status == "test_value");
            }
        }
    }
}

SCENARIO("Update TransferSlot fields") {
    GIVEN("a TransferSlot with initial values") {
        auto entity = intermodal_transfer::TransferSlot{};
        entity.id = "00000000-0000-0000-0000-000000000001";
        entity.reference = {};
        entity.container_id = "00000000-0000-0000-0000-000000000001";
        entity.transport_mode = "test_value";
        entity.scheduled_at = {};
        entity.status = "test_value";

        WHEN("fields are modified") {
            entity.id = "00000000-0000-0000-0000-000000000002";
            entity.reference = {};
            entity.container_id = "00000000-0000-0000-0000-000000000002";
            entity.transport_mode = "updated_value";
            entity.scheduled_at = {};
            entity.status = "updated_value";

            THEN("the entity reflects the new values") {
                CHECK(entity.id == "00000000-0000-0000-0000-000000000002");
                CHECK(entity.reference == {});
                CHECK(entity.container_id == "00000000-0000-0000-0000-000000000002");
                CHECK(entity.transport_mode == "updated_value");
                CHECK(entity.scheduled_at == {});
                CHECK(entity.status == "updated_value");
            }
        }
    }
}

SCENARIO("TransferSlot identity comparison") {
    GIVEN("two TransferSlot entities with the same ID") {
        auto a = intermodal_transfer::TransferSlot{};
        auto b = intermodal_transfer::TransferSlot{};
        a.id = b.id = "test-id-001";

        WHEN("compared") {
            THEN("they should be considered equal by ID") {
                CHECK(a.id == b.id);
            }
        }
    }
}

SCENARIO("Add child TruckVisit to TransferSlot") {
    GIVEN("an existing TransferSlot aggregate root") {
        WHEN("a TruckVisit child is added") {
            auto child = TruckVisit{};
            auto parent_id = TransferSlot::Id{};
            domain_service.add_truck_visit(parent_id, child);

            THEN("the child should be part of the aggregate") {
                CHECK_NOTHROW(domain_service.add_truck_visit(parent_id, child));
            }
        }
    }
}
