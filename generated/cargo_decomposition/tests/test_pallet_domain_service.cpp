// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>

// Test skeleton for PalletDomainService
// Uses doctest BDD style (SCENARIO/GIVEN/WHEN/THEN)


SCENARIO("PalletDomainService creates a Pallet") {
    GIVEN("a valid Pallet entity") {
        auto entity = cargo_decomposition::Pallet{};
        entity.id = "test-create-001";
        entity.id = "00000000-0000-0000-0000-000000000001";
        entity.pallet_id = {};
        entity.container_id = "00000000-0000-0000-0000-000000000001";
        entity.weight_kg = 3.14;
        entity.length_cm = 3.14;
        entity.width_cm = 3.14;
        entity.height_cm = 3.14;
        entity.hs_code = {};

        THEN("the entity should have its ID set") {
            CHECK(entity.id == "test-create-001");
        }
    }
}

SCENARIO("PalletDomainService updates a Pallet") {
    GIVEN("an existing Pallet entity") {
        auto entity = cargo_decomposition::Pallet{};
        entity.id = "test-update-001";
        entity.id = "00000000-0000-0000-0000-000000000001";
        entity.pallet_id = {};
        entity.container_id = "00000000-0000-0000-0000-000000000001";
        entity.weight_kg = 3.14;
        entity.length_cm = 3.14;
        entity.width_cm = 3.14;
        entity.height_cm = 3.14;
        entity.hs_code = {};

        WHEN("the entity is modified") {
            entity.id = "00000000-0000-0000-0000-000000000002";
            entity.pallet_id = {};
            entity.container_id = "00000000-0000-0000-0000-000000000002";
            entity.weight_kg = 6.28;
            entity.length_cm = 6.28;
            entity.width_cm = 6.28;
            entity.height_cm = 6.28;
            entity.hs_code = {};

            THEN("the entity should reflect the changes") {
                CHECK(entity.id == "test-update-001");
                CHECK(entity.id == "00000000-0000-0000-0000-000000000002");
                CHECK(entity.pallet_id == {});
                CHECK(entity.container_id == "00000000-0000-0000-0000-000000000002");
                CHECK(entity.weight_kg == doctest::Approx(6.28));
                CHECK(entity.length_cm == doctest::Approx(6.28));
                CHECK(entity.width_cm == doctest::Approx(6.28));
                CHECK(entity.height_cm == doctest::Approx(6.28));
                CHECK(entity.hs_code == {});
            }
        }
    }
}

SCENARIO("PalletDomainService manages Pallet lifecycle") {
    GIVEN("a Pallet entity") {
        auto entity = cargo_decomposition::Pallet{};
        entity.id = "test-lifecycle-001";

        THEN("the entity ID should be non-empty") {
            CHECK_FALSE(entity.id.empty());
        }
    }
}
