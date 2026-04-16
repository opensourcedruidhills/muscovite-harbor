// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>

// Test skeleton for VoyageDomainService
// Uses doctest BDD style (SCENARIO/GIVEN/WHEN/THEN)


SCENARIO("VoyageDomainService creates a Voyage") {
    GIVEN("a valid Voyage entity") {
        auto entity = vessel_traffic::Voyage{};
        entity.id = "test-create-001";
        entity.id = "00000000-0000-0000-0000-000000000001";
        entity.vessel_id = "00000000-0000-0000-0000-000000000001";
        entity.berth_id = "00000000-0000-0000-0000-000000000001";
        entity.voyage_number = "test_value";
        entity.eta = {};
        entity.ata = {};
        entity.etd = {};
        entity.atd = {};
        entity.cargo_category = "test_value";
        entity.status = "test_value";

        THEN("the entity should have its ID set") {
            CHECK(entity.id == "test-create-001");
        }
    }
}

SCENARIO("VoyageDomainService updates a Voyage") {
    GIVEN("an existing Voyage entity") {
        auto entity = vessel_traffic::Voyage{};
        entity.id = "test-update-001";
        entity.id = "00000000-0000-0000-0000-000000000001";
        entity.vessel_id = "00000000-0000-0000-0000-000000000001";
        entity.berth_id = "00000000-0000-0000-0000-000000000001";
        entity.voyage_number = "test_value";
        entity.eta = {};
        entity.ata = {};
        entity.etd = {};
        entity.atd = {};
        entity.cargo_category = "test_value";
        entity.status = "test_value";

        WHEN("the entity is modified") {
            entity.id = "00000000-0000-0000-0000-000000000002";
            entity.vessel_id = "00000000-0000-0000-0000-000000000002";
            entity.berth_id = "00000000-0000-0000-0000-000000000002";
            entity.voyage_number = "updated_value";
            entity.eta = {};
            entity.ata = {};
            entity.etd = {};
            entity.atd = {};
            entity.cargo_category = "updated_value";
            entity.status = "updated_value";

            THEN("the entity should reflect the changes") {
                CHECK(entity.id == "test-update-001");
                CHECK(entity.id == "00000000-0000-0000-0000-000000000002");
                CHECK(entity.vessel_id == "00000000-0000-0000-0000-000000000002");
                CHECK(entity.berth_id == "00000000-0000-0000-0000-000000000002");
                CHECK(entity.voyage_number == "updated_value");
                CHECK(entity.eta == {});
                CHECK(entity.ata == {});
                CHECK(entity.etd == {});
                CHECK(entity.atd == {});
                CHECK(entity.cargo_category == "updated_value");
                CHECK(entity.status == "updated_value");
            }
        }
    }
}

SCENARIO("VoyageDomainService manages Voyage lifecycle") {
    GIVEN("a Voyage entity") {
        auto entity = vessel_traffic::Voyage{};
        entity.id = "test-lifecycle-001";

        THEN("the entity ID should be non-empty") {
            CHECK_FALSE(entity.id.empty());
        }
    }
}
