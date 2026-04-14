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

        WHEN("the entity is created via command service") {
            // auto result = cmd_service.create(entity);

            THEN("it should be persisted successfully") {
                // CHECK(result.has_value());
            }
        }
    }
}

SCENARIO("Find Parcel by ID") {
    GIVEN("an existing Parcel") {
        WHEN("queried by its ID") {
            // auto found = query_service.find_by_id(id);

            THEN("the entity should be returned") {
                // CHECK(found.has_value());
            }
        }
    }
}

SCENARIO("Find all Parcel") {
    GIVEN("multiple Parcel entities exist") {
        WHEN("all are queried") {
            // auto all = query_service.find_all();

            THEN("all entities should be returned") {
                // CHECK(!all.empty());
            }
        }
    }
}

SCENARIO("Update Parcel") {
    GIVEN("an existing Parcel") {
        WHEN("a field is modified and saved") {
            // auto updated = cmd_service.update(entity);

            THEN("the change should be persisted") {
                // CHECK(updated.has_value());
            }
        }
    }
}

SCENARIO("Remove Parcel") {
    GIVEN("an existing Parcel") {
        WHEN("the entity is removed") {
            // cmd_service.remove(id);

            THEN("it should no longer be findable") {
                // auto found = query_service.find_by_id(id);
                // CHECK(!found.has_value());
            }
        }
    }
}

SCENARIO("Add child DeliveryUnit to Parcel") {
    GIVEN("an existing Parcel aggregate root") {
        WHEN("a DeliveryUnit child is added") {
            // auto result = cmd_service.add_child(parent_id, child);

            THEN("the child should be part of the aggregate") {
                // CHECK(result.has_value());
            }
        }
    }
}
