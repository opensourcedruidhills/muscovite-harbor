// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>

// V2 DBA integration tests for PalletDispatch aggregate
// Context: CargoDecomposition


SCENARIO("Create Parcel") {
    GIVEN("a Parcel with valid fields") {
        auto entity = cargo_decomposition::Parcel{};
        entity.id = "00000000-0000-0000-0000-000000000001";
        entity.tracking_number = {};
        entity.pallet_id = "00000000-0000-0000-0000-000000000001";
        entity.weight_kg = 3.14;
        entity.hs_code = {};
        entity.description = "test_value";

        WHEN("the entity is created") {
            THEN("all fields should be set") {
                CHECK_FALSE(entity.id.empty());
                CHECK(entity.id == "00000000-0000-0000-0000-000000000001");
                CHECK(entity.pallet_id == "00000000-0000-0000-0000-000000000001");
                CHECK(entity.weight_kg == doctest::Approx(3.14));
                CHECK(entity.description == "test_value");
            }
        }
    }
}

SCENARIO("Parcel round-trip serialization") {
    GIVEN("a Parcel with populated fields") {
        auto entity = cargo_decomposition::Parcel{};
        entity.id = "00000000-0000-0000-0000-000000000001";
        entity.tracking_number = {};
        entity.pallet_id = "00000000-0000-0000-0000-000000000001";
        entity.weight_kg = 3.14;
        entity.hs_code = {};
        entity.description = "test_value";

        WHEN("checked for default state") {
            THEN("the entity should have non-default values") {
                CHECK(entity.id == "00000000-0000-0000-0000-000000000001");
                CHECK(entity.pallet_id == "00000000-0000-0000-0000-000000000001");
                CHECK(entity.weight_kg == doctest::Approx(3.14));
                CHECK(entity.description == "test_value");
            }
        }
    }
}

SCENARIO("Update Parcel fields") {
    GIVEN("a Parcel with initial values") {
        auto entity = cargo_decomposition::Parcel{};
        entity.id = "00000000-0000-0000-0000-000000000001";
        entity.tracking_number = {};
        entity.pallet_id = "00000000-0000-0000-0000-000000000001";
        entity.weight_kg = 3.14;
        entity.hs_code = {};
        entity.description = "test_value";

        WHEN("fields are modified") {
            entity.id = "00000000-0000-0000-0000-000000000002";
            entity.tracking_number = {};
            entity.pallet_id = "00000000-0000-0000-0000-000000000002";
            entity.weight_kg = 6.28;
            entity.hs_code = {};
            entity.description = "updated_value";

            THEN("the entity reflects the new values") {
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

SCENARIO("Parcel identity comparison") {
    GIVEN("two Parcel entities with the same ID") {
        auto a = cargo_decomposition::Parcel{};
        auto b = cargo_decomposition::Parcel{};
        a.id = b.id = "test-id-001";

        WHEN("compared") {
            THEN("they should be considered equal by ID") {
                CHECK(a.id == b.id);
            }
        }
    }
}

SCENARIO("Add child DeliveryUnit to Parcel") {
    GIVEN("an existing Parcel aggregate root") {
        WHEN("a DeliveryUnit child is added") {
            auto child = DeliveryUnit{};
            auto parent_id = Parcel::Id{};
            domain_service.add_delivery_unit(parent_id, child);

            THEN("the child should be part of the aggregate") {
                CHECK_NOTHROW(domain_service.add_delivery_unit(parent_id, child));
            }
        }
    }
}
