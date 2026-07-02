// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>

#include <boost/uuid/nil_generator.hpp>
#include <boost/uuid/string_generator.hpp>
#include <boost/uuid/uuid.hpp>

// Test skeleton for LoadPlanDomainService
// Uses doctest BDD style (SCENARIO/GIVEN/WHEN/THEN)


SCENARIO("LoadPlanDomainService creates a LoadPlan") {
    GIVEN("a valid LoadPlan create request") {
        auto create_request = cargo_operations::LoadPlan{};
        create_request.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        create_request.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        create_request.voyage_id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        create_request.created_at = {};
        create_request.status = "test_value";
        auto create_operation = [](const cargo_operations::LoadPlan& entity) {
            return entity;
        };

        WHEN("the create operation is executed") {
            auto created = create_operation(create_request);

            THEN("the created entity preserves the requested values") {
                CHECK(created.id == create_request.id);
                CHECK(created.id == create_request.id);
                CHECK(created.voyage_id == create_request.voyage_id);
                CHECK(created.created_at == create_request.created_at);
                CHECK(created.status == create_request.status);
            }
        }
    }
}

SCENARIO("LoadPlanDomainService updates a LoadPlan") {
    GIVEN("an existing LoadPlan entity") {
        auto existing_entity = cargo_operations::LoadPlan{};
        existing_entity.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000002");
        existing_entity.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        existing_entity.voyage_id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        existing_entity.created_at = {};
        existing_entity.status = "test_value";
        auto update_request = existing_entity;
        update_request.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000002");
        update_request.voyage_id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000002");
        update_request.created_at = {};
        update_request.status = "updated_value";
        auto update_operation = [](const cargo_operations::LoadPlan& entity) {
            return entity;
        };

        WHEN("the update operation is executed") {
            auto updated = update_operation(update_request);

            THEN("the updated entity reflects the requested changes") {
                CHECK(updated.id == update_request.id);
                CHECK(updated.id == update_request.id);
                CHECK(updated.voyage_id == update_request.voyage_id);
                CHECK(updated.created_at == update_request.created_at);
                CHECK(updated.status == update_request.status);
            }
        }
    }
}

SCENARIO("LoadPlanDomainService manages LoadPlan lifecycle") {
    GIVEN("a LoadPlan entity scheduled for removal") {
        auto lifecycle_entity = cargo_operations::LoadPlan{};
        lifecycle_entity.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000003");
        auto remove_operation = [](const cargo_operations::LoadPlan& entity) {
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
