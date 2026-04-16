// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>

// Test skeleton for TransferSlotDomainService
// Uses doctest BDD style (SCENARIO/GIVEN/WHEN/THEN)


SCENARIO("TransferSlotDomainService creates a TransferSlot") {
    GIVEN("a valid TransferSlot entity") {
        auto entity = intermodal_transfer::TransferSlot{};
        entity.id = "test-create-001";
        entity.id = "00000000-0000-0000-0000-000000000001";
        entity.reference = {};
        entity.container_id = "00000000-0000-0000-0000-000000000001";
        entity.transport_mode = "test_value";
        entity.scheduled_at = {};
        entity.status = "test_value";

        THEN("the entity should have its ID set") {
            CHECK(entity.id == "test-create-001");
        }
    }
}

SCENARIO("TransferSlotDomainService updates a TransferSlot") {
    GIVEN("an existing TransferSlot entity") {
        auto entity = intermodal_transfer::TransferSlot{};
        entity.id = "test-update-001";
        entity.id = "00000000-0000-0000-0000-000000000001";
        entity.reference = {};
        entity.container_id = "00000000-0000-0000-0000-000000000001";
        entity.transport_mode = "test_value";
        entity.scheduled_at = {};
        entity.status = "test_value";

        WHEN("the entity is modified") {
            entity.id = "00000000-0000-0000-0000-000000000002";
            entity.reference = {};
            entity.container_id = "00000000-0000-0000-0000-000000000002";
            entity.transport_mode = "updated_value";
            entity.scheduled_at = {};
            entity.status = "updated_value";

            THEN("the entity should reflect the changes") {
                CHECK(entity.id == "test-update-001");
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

SCENARIO("TransferSlotDomainService manages TransferSlot lifecycle") {
    GIVEN("a TransferSlot entity") {
        auto entity = intermodal_transfer::TransferSlot{};
        entity.id = "test-lifecycle-001";

        THEN("the entity ID should be non-empty") {
            CHECK_FALSE(entity.id.empty());
        }
    }
}
