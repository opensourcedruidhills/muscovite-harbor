// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>

// Test skeleton for ParcelDomainService
// Uses doctest BDD style (SCENARIO/GIVEN/WHEN/THEN)


SCENARIO("ParcelDomainService creates a Parcel") {
    GIVEN("a valid Parcel entity") {
        auto entity = cargo_decomposition::Parcel{};
        entity.id = "test-create-001";
        entity.id = "00000000-0000-0000-0000-000000000001";
        entity.tracking_number = {};
        entity.pallet_id = "00000000-0000-0000-0000-000000000001";
        entity.weight_kg = 3.14;
        entity.hs_code = {};
        entity.description = "test_value";

        THEN("the entity should have its ID set") {
            CHECK(entity.id == "test-create-001");
        }
    }
}

SCENARIO("ParcelDomainService updates a Parcel") {
    GIVEN("an existing Parcel entity") {
        auto entity = cargo_decomposition::Parcel{};
        entity.id = "test-update-001";
        entity.id = "00000000-0000-0000-0000-000000000001";
        entity.tracking_number = {};
        entity.pallet_id = "00000000-0000-0000-0000-000000000001";
        entity.weight_kg = 3.14;
        entity.hs_code = {};
        entity.description = "test_value";

        WHEN("the entity is modified") {
            entity.id = "00000000-0000-0000-0000-000000000002";
            entity.tracking_number = {};
            entity.pallet_id = "00000000-0000-0000-0000-000000000002";
            entity.weight_kg = 6.28;
            entity.hs_code = {};
            entity.description = "updated_value";

            THEN("the entity should reflect the changes") {
                CHECK(entity.id == "test-update-001");
                CHECK(entity.id == "00000000-0000-0000-0000-000000000002");
                CHECK(entity.tracking_number == {});
                CHECK(entity.pallet_id == "00000000-0000-0000-0000-000000000002");
                CHECK(entity.weight_kg == doctest::Approx(6.28));
                CHECK(entity.hs_code == {});
                CHECK(entity.description == "updated_value");
            }
        }
    }
}

SCENARIO("ParcelDomainService manages Parcel lifecycle") {
    GIVEN("a Parcel entity") {
        auto entity = cargo_decomposition::Parcel{};
        entity.id = "test-lifecycle-001";

        THEN("the entity ID should be non-empty") {
            CHECK_FALSE(entity.id.empty());
        }
    }
}
