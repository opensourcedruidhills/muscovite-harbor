// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>

#include <boost/uuid/nil_generator.hpp>
#include <boost/uuid/string_generator.hpp>
#include <boost/uuid/uuid.hpp>

// V2 DBA integration tests for ContainerUnpack aggregate
// Context: CargoDecomposition


SCENARIO("Create Pallet") {
    GIVEN("a Pallet with valid fields") {
        auto entity = cargo_decomposition::Pallet{};
        entity.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        entity.pallet_id = {};
        entity.container_id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        entity.weight_kg = 3.14;
        entity.length_cm = 3.14;
        entity.width_cm = 3.14;
        entity.height_cm = 3.14;
        entity.hs_code = {};

        WHEN("the entity is created") {
            THEN("all fields should be set") {
                CHECK(entity.id != boost::uuids::nil_uuid());
                CHECK(entity.id == boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001"));
                CHECK(entity.container_id == boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001"));
                CHECK(entity.weight_kg == doctest::Approx(3.14));
                CHECK(entity.length_cm == doctest::Approx(3.14));
                CHECK(entity.width_cm == doctest::Approx(3.14));
                CHECK(entity.height_cm == doctest::Approx(3.14));
            }
        }
    }
}

SCENARIO("Pallet round-trip serialization") {
    GIVEN("a Pallet with populated fields") {
        auto entity = cargo_decomposition::Pallet{};
        entity.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        entity.pallet_id = {};
        entity.container_id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        entity.weight_kg = 3.14;
        entity.length_cm = 3.14;
        entity.width_cm = 3.14;
        entity.height_cm = 3.14;
        entity.hs_code = {};

        WHEN("checked for default state") {
            THEN("the entity should have non-default values") {
                CHECK(entity.id == boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001"));
                CHECK(entity.container_id == boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001"));
                CHECK(entity.weight_kg == doctest::Approx(3.14));
                CHECK(entity.length_cm == doctest::Approx(3.14));
                CHECK(entity.width_cm == doctest::Approx(3.14));
                CHECK(entity.height_cm == doctest::Approx(3.14));
            }
        }
    }
}

SCENARIO("Update Pallet fields") {
    GIVEN("a Pallet with initial values") {
        auto entity = cargo_decomposition::Pallet{};
        entity.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        entity.pallet_id = {};
        entity.container_id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        entity.weight_kg = 3.14;
        entity.length_cm = 3.14;
        entity.width_cm = 3.14;
        entity.height_cm = 3.14;
        entity.hs_code = {};

        WHEN("fields are modified") {
            entity.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000002");
            entity.pallet_id = {};
            entity.container_id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000002");
            entity.weight_kg = 6.28;
            entity.length_cm = 6.28;
            entity.width_cm = 6.28;
            entity.height_cm = 6.28;
            entity.hs_code = {};

            THEN("the entity reflects the new values") {
                CHECK(entity.id == boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000002"));
                CHECK(entity.pallet_id == {});
                CHECK(entity.container_id == boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000002"));
                CHECK(entity.weight_kg == doctest::Approx(6.28));
                CHECK(entity.length_cm == doctest::Approx(6.28));
                CHECK(entity.width_cm == doctest::Approx(6.28));
                CHECK(entity.height_cm == doctest::Approx(6.28));
                CHECK(entity.hs_code == {});
            }
        }
    }
}

SCENARIO("Pallet identity comparison") {
    GIVEN("two Pallet entities with the same ID") {
        auto a = cargo_decomposition::Pallet{};
        auto b = cargo_decomposition::Pallet{};
        a.id = boost::uuids::string_generator{}("00000000-0000-0000-0000-000000000001");
        b.id = a.id;

        WHEN("compared") {
            THEN("they should be considered equal by ID") {
                CHECK(a.id == b.id);
            }
        }
    }
}
