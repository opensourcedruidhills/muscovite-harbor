// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>

#include <boost/uuid/nil_generator.hpp>
#include <boost/uuid/string_generator.hpp>
#include <boost/uuid/uuid.hpp>

// Test skeleton for ParcelDomainService
// Uses doctest BDD style (SCENARIO/GIVEN/WHEN/THEN)


SCENARIO("ParcelDomainService creates a Parcel") {
    GIVEN("a valid Parcel create request") {
        auto create_request = cargo_decomposition::Parcel{};
        create_request.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        create_request.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        create_request.tracking_number = {};
        create_request.pallet_id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        create_request.weight_kg = 3.14;
        create_request.hs_code = {};
        create_request.description = "test_value";
        auto create_operation = [](const cargo_decomposition::Parcel& entity) {
            return entity;
        };

        WHEN("the create operation is executed") {
            auto created = create_operation(create_request);

            THEN("the created entity preserves the requested values") {
                CHECK(created.id == create_request.id);
                CHECK(created.id == create_request.id);
                CHECK(created.tracking_number == create_request.tracking_number);
                CHECK(created.pallet_id == create_request.pallet_id);
                CHECK(created.weight_kg == doctest::Approx(create_request.weight_kg));
                CHECK(created.hs_code == create_request.hs_code);
                CHECK(created.description == create_request.description);
            }
        }
    }
}

SCENARIO("ParcelDomainService updates a Parcel") {
    GIVEN("an existing Parcel entity") {
        auto existing_entity = cargo_decomposition::Parcel{};
        existing_entity.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000002");
        existing_entity.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        existing_entity.tracking_number = {};
        existing_entity.pallet_id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        existing_entity.weight_kg = 3.14;
        existing_entity.hs_code = {};
        existing_entity.description = "test_value";
        auto update_request = existing_entity;
        update_request.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000002");
        update_request.tracking_number = {};
        update_request.pallet_id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000002");
        update_request.weight_kg = 6.28;
        update_request.hs_code = {};
        update_request.description = "updated_value";
        auto update_operation = [](const cargo_decomposition::Parcel& entity) {
            return entity;
        };

        WHEN("the update operation is executed") {
            auto updated = update_operation(update_request);

            THEN("the updated entity reflects the requested changes") {
                CHECK(updated.id == update_request.id);
                CHECK(updated.id == update_request.id);
                CHECK(updated.tracking_number == update_request.tracking_number);
                CHECK(updated.pallet_id == update_request.pallet_id);
                CHECK(updated.weight_kg == doctest::Approx(update_request.weight_kg));
                CHECK(updated.hs_code == update_request.hs_code);
                CHECK(updated.description == update_request.description);
            }
        }
    }
}

SCENARIO("ParcelDomainService manages Parcel lifecycle") {
    GIVEN("a Parcel entity scheduled for removal") {
        auto lifecycle_entity = cargo_decomposition::Parcel{};
        lifecycle_entity.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000003");
        auto remove_operation = [](const cargo_decomposition::Parcel& entity) {
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
