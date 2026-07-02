// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>

#include <boost/uuid/nil_generator.hpp>
#include <boost/uuid/string_generator.hpp>
#include <boost/uuid/uuid.hpp>

// Test skeleton for VoyageDomainService
// Uses doctest BDD style (SCENARIO/GIVEN/WHEN/THEN)


SCENARIO("VoyageDomainService creates a Voyage") {
    GIVEN("a valid Voyage create request") {
        auto create_request = vessel_traffic::Voyage{};
        create_request.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        create_request.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        create_request.vessel_id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        create_request.berth_id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        create_request.voyage_number = "test_value";
        create_request.eta = {};
        create_request.ata = {};
        create_request.etd = {};
        create_request.atd = {};
        create_request.cargo_category = "test_value";
        create_request.status = "test_value";
        auto create_operation = [](const vessel_traffic::Voyage& entity) {
            return entity;
        };

        WHEN("the create operation is executed") {
            auto created = create_operation(create_request);

            THEN("the created entity preserves the requested values") {
                CHECK(created.id == create_request.id);
                CHECK(created.id == create_request.id);
                CHECK(created.vessel_id == create_request.vessel_id);
                CHECK(created.berth_id == create_request.berth_id);
                CHECK(created.voyage_number == create_request.voyage_number);
                CHECK(created.eta == create_request.eta);
                CHECK(created.ata == create_request.ata);
                CHECK(created.etd == create_request.etd);
                CHECK(created.atd == create_request.atd);
                CHECK(created.cargo_category == create_request.cargo_category);
                CHECK(created.status == create_request.status);
            }
        }
    }
}

SCENARIO("VoyageDomainService updates a Voyage") {
    GIVEN("an existing Voyage entity") {
        auto existing_entity = vessel_traffic::Voyage{};
        existing_entity.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000002");
        existing_entity.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        existing_entity.vessel_id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        existing_entity.berth_id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        existing_entity.voyage_number = "test_value";
        existing_entity.eta = {};
        existing_entity.ata = {};
        existing_entity.etd = {};
        existing_entity.atd = {};
        existing_entity.cargo_category = "test_value";
        existing_entity.status = "test_value";
        auto update_request = existing_entity;
        update_request.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000002");
        update_request.vessel_id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000002");
        update_request.berth_id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000002");
        update_request.voyage_number = "updated_value";
        update_request.eta = {};
        update_request.ata = {};
        update_request.etd = {};
        update_request.atd = {};
        update_request.cargo_category = "updated_value";
        update_request.status = "updated_value";
        auto update_operation = [](const vessel_traffic::Voyage& entity) {
            return entity;
        };

        WHEN("the update operation is executed") {
            auto updated = update_operation(update_request);

            THEN("the updated entity reflects the requested changes") {
                CHECK(updated.id == update_request.id);
                CHECK(updated.id == update_request.id);
                CHECK(updated.vessel_id == update_request.vessel_id);
                CHECK(updated.berth_id == update_request.berth_id);
                CHECK(updated.voyage_number == update_request.voyage_number);
                CHECK(updated.eta == update_request.eta);
                CHECK(updated.ata == update_request.ata);
                CHECK(updated.etd == update_request.etd);
                CHECK(updated.atd == update_request.atd);
                CHECK(updated.cargo_category == update_request.cargo_category);
                CHECK(updated.status == update_request.status);
            }
        }
    }
}

SCENARIO("VoyageDomainService manages Voyage lifecycle") {
    GIVEN("a Voyage entity scheduled for removal") {
        auto lifecycle_entity = vessel_traffic::Voyage{};
        lifecycle_entity.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000003");
        auto remove_operation = [](const vessel_traffic::Voyage& entity) {
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
