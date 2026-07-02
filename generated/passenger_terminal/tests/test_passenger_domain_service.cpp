// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>

#include <boost/uuid/nil_generator.hpp>
#include <boost/uuid/string_generator.hpp>
#include <boost/uuid/uuid.hpp>

// Test skeleton for PassengerDomainService
// Uses doctest BDD style (SCENARIO/GIVEN/WHEN/THEN)


SCENARIO("PassengerDomainService creates a Passenger") {
    GIVEN("a valid Passenger create request") {
        auto create_request = passenger_terminal::Passenger{};
        create_request.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        create_request.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        create_request.booking_ref = {};
        create_request.passenger_type = "test_value";
        create_request.voyage_id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        create_request.status = "test_value";
        auto create_operation = [](const passenger_terminal::Passenger& entity) {
            return entity;
        };

        WHEN("the create operation is executed") {
            auto created = create_operation(create_request);

            THEN("the created entity preserves the requested values") {
                CHECK(created.id == create_request.id);
                CHECK(created.id == create_request.id);
                CHECK(created.booking_ref == create_request.booking_ref);
                CHECK(created.passenger_type == create_request.passenger_type);
                CHECK(created.voyage_id == create_request.voyage_id);
                CHECK(created.status == create_request.status);
            }
        }
    }
}

SCENARIO("PassengerDomainService updates a Passenger") {
    GIVEN("an existing Passenger entity") {
        auto existing_entity = passenger_terminal::Passenger{};
        existing_entity.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000002");
        existing_entity.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        existing_entity.booking_ref = {};
        existing_entity.passenger_type = "test_value";
        existing_entity.voyage_id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        existing_entity.status = "test_value";
        auto update_request = existing_entity;
        update_request.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000002");
        update_request.booking_ref = {};
        update_request.passenger_type = "updated_value";
        update_request.voyage_id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000002");
        update_request.status = "updated_value";
        auto update_operation = [](const passenger_terminal::Passenger& entity) {
            return entity;
        };

        WHEN("the update operation is executed") {
            auto updated = update_operation(update_request);

            THEN("the updated entity reflects the requested changes") {
                CHECK(updated.id == update_request.id);
                CHECK(updated.id == update_request.id);
                CHECK(updated.booking_ref == update_request.booking_ref);
                CHECK(updated.passenger_type == update_request.passenger_type);
                CHECK(updated.voyage_id == update_request.voyage_id);
                CHECK(updated.status == update_request.status);
            }
        }
    }
}

SCENARIO("PassengerDomainService manages Passenger lifecycle") {
    GIVEN("a Passenger entity scheduled for removal") {
        auto lifecycle_entity = passenger_terminal::Passenger{};
        lifecycle_entity.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000003");
        auto remove_operation = [](const passenger_terminal::Passenger& entity) {
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
