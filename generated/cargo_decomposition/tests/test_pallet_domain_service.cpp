// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>

#include <boost/uuid/nil_generator.hpp>
#include <boost/uuid/string_generator.hpp>
#include <boost/uuid/uuid.hpp>

// Test skeleton for PalletDomainService
// Uses doctest BDD style (SCENARIO/GIVEN/WHEN/THEN)


SCENARIO("PalletDomainService creates a Pallet") {
    GIVEN("a valid Pallet create request") {
        auto create_request = cargo_decomposition::Pallet{};
        create_request.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        create_request.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        create_request.pallet_id = {};
        create_request.container_id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        create_request.weight_kg = 3.14;
        create_request.length_cm = 3.14;
        create_request.width_cm = 3.14;
        create_request.height_cm = 3.14;
        create_request.hs_code = {};
        auto create_operation = [](const cargo_decomposition::Pallet& entity) {
            return entity;
        };

        WHEN("the create operation is executed") {
            auto created = create_operation(create_request);

            THEN("the created entity preserves the requested values") {
                CHECK(created.id == create_request.id);
                CHECK(created.id == create_request.id);
                CHECK(created.pallet_id == create_request.pallet_id);
                CHECK(created.container_id == create_request.container_id);
                CHECK(created.weight_kg == doctest::Approx(create_request.weight_kg));
                CHECK(created.length_cm == doctest::Approx(create_request.length_cm));
                CHECK(created.width_cm == doctest::Approx(create_request.width_cm));
                CHECK(created.height_cm == doctest::Approx(create_request.height_cm));
                CHECK(created.hs_code == create_request.hs_code);
            }
        }
    }
}

SCENARIO("PalletDomainService updates a Pallet") {
    GIVEN("an existing Pallet entity") {
        auto existing_entity = cargo_decomposition::Pallet{};
        existing_entity.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000002");
        existing_entity.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        existing_entity.pallet_id = {};
        existing_entity.container_id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        existing_entity.weight_kg = 3.14;
        existing_entity.length_cm = 3.14;
        existing_entity.width_cm = 3.14;
        existing_entity.height_cm = 3.14;
        existing_entity.hs_code = {};
        auto update_request = existing_entity;
        update_request.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000002");
        update_request.pallet_id = {};
        update_request.container_id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000002");
        update_request.weight_kg = 6.28;
        update_request.length_cm = 6.28;
        update_request.width_cm = 6.28;
        update_request.height_cm = 6.28;
        update_request.hs_code = {};
        auto update_operation = [](const cargo_decomposition::Pallet& entity) {
            return entity;
        };

        WHEN("the update operation is executed") {
            auto updated = update_operation(update_request);

            THEN("the updated entity reflects the requested changes") {
                CHECK(updated.id == update_request.id);
                CHECK(updated.id == update_request.id);
                CHECK(updated.pallet_id == update_request.pallet_id);
                CHECK(updated.container_id == update_request.container_id);
                CHECK(updated.weight_kg == doctest::Approx(update_request.weight_kg));
                CHECK(updated.length_cm == doctest::Approx(update_request.length_cm));
                CHECK(updated.width_cm == doctest::Approx(update_request.width_cm));
                CHECK(updated.height_cm == doctest::Approx(update_request.height_cm));
                CHECK(updated.hs_code == update_request.hs_code);
            }
        }
    }
}

SCENARIO("PalletDomainService manages Pallet lifecycle") {
    GIVEN("a Pallet entity scheduled for removal") {
        auto lifecycle_entity = cargo_decomposition::Pallet{};
        lifecycle_entity.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000003");
        auto remove_operation = [](const cargo_decomposition::Pallet& entity) {
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
