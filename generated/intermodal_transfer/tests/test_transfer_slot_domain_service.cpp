// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>

#include <boost/uuid/nil_generator.hpp>
#include <boost/uuid/string_generator.hpp>
#include <boost/uuid/uuid.hpp>

// Test skeleton for TransferSlotDomainService
// Uses doctest BDD style (SCENARIO/GIVEN/WHEN/THEN)


SCENARIO("TransferSlotDomainService creates a TransferSlot") {
    GIVEN("a valid TransferSlot create request") {
        auto create_request = intermodal_transfer::TransferSlot{};
        create_request.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        create_request.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        create_request.reference = {};
        create_request.container_id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        create_request.transport_mode = "test_value";
        create_request.scheduled_at = {};
        create_request.status = "test_value";
        auto create_operation = [](const intermodal_transfer::TransferSlot& entity) {
            return entity;
        };

        WHEN("the create operation is executed") {
            auto created = create_operation(create_request);

            THEN("the created entity preserves the requested values") {
                CHECK(created.id == create_request.id);
                CHECK(created.id == create_request.id);
                CHECK(created.reference == create_request.reference);
                CHECK(created.container_id == create_request.container_id);
                CHECK(created.transport_mode == create_request.transport_mode);
                CHECK(created.scheduled_at == create_request.scheduled_at);
                CHECK(created.status == create_request.status);
            }
        }
    }
}

SCENARIO("TransferSlotDomainService updates a TransferSlot") {
    GIVEN("an existing TransferSlot entity") {
        auto existing_entity = intermodal_transfer::TransferSlot{};
        existing_entity.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000002");
        existing_entity.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        existing_entity.reference = {};
        existing_entity.container_id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        existing_entity.transport_mode = "test_value";
        existing_entity.scheduled_at = {};
        existing_entity.status = "test_value";
        auto update_request = existing_entity;
        update_request.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000002");
        update_request.reference = {};
        update_request.container_id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000002");
        update_request.transport_mode = "updated_value";
        update_request.scheduled_at = {};
        update_request.status = "updated_value";
        auto update_operation = [](const intermodal_transfer::TransferSlot& entity) {
            return entity;
        };

        WHEN("the update operation is executed") {
            auto updated = update_operation(update_request);

            THEN("the updated entity reflects the requested changes") {
                CHECK(updated.id == update_request.id);
                CHECK(updated.id == update_request.id);
                CHECK(updated.reference == update_request.reference);
                CHECK(updated.container_id == update_request.container_id);
                CHECK(updated.transport_mode == update_request.transport_mode);
                CHECK(updated.scheduled_at == update_request.scheduled_at);
                CHECK(updated.status == update_request.status);
            }
        }
    }
}

SCENARIO("TransferSlotDomainService manages TransferSlot lifecycle") {
    GIVEN("a TransferSlot entity scheduled for removal") {
        auto lifecycle_entity = intermodal_transfer::TransferSlot{};
        lifecycle_entity.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000003");
        auto remove_operation = [](const intermodal_transfer::TransferSlot& entity) {
            return entity.id;
        };

        WHEN("the remove operation is addressed") {
            auto removed_id = remove_operation(lifecycle_entity);

            THEN("the addressed ID remains stable and non-nil") {
                CHECK(removed_id == lifecycle_entity.id);
                CHECK(removed_id != boost::uuids::nil_uuid());
            }
        }
    }
}
