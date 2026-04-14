// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>

// V2 DBA integration tests for VesselCall aggregate
// Context: VesselTraffic


SCENARIO("Create Voyage") {
    GIVEN("a Voyage with valid fields") {
        auto entity = vessel_traffic::Voyage{};
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

        WHEN("the entity is created via command service") {
            // auto result = cmd_service.create(entity);

            THEN("it should be persisted successfully") {
                // CHECK(result.has_value());
            }
        }
    }
}

SCENARIO("Find Voyage by ID") {
    GIVEN("an existing Voyage") {
        WHEN("queried by its ID") {
            // auto found = query_service.find_by_id(id);

            THEN("the entity should be returned") {
                // CHECK(found.has_value());
            }
        }
    }
}

SCENARIO("Find all Voyage") {
    GIVEN("multiple Voyage entities exist") {
        WHEN("all are queried") {
            // auto all = query_service.find_all();

            THEN("all entities should be returned") {
                // CHECK(!all.empty());
            }
        }
    }
}

SCENARIO("Update Voyage") {
    GIVEN("an existing Voyage") {
        WHEN("a field is modified and saved") {
            // auto updated = cmd_service.update(entity);

            THEN("the change should be persisted") {
                // CHECK(updated.has_value());
            }
        }
    }
}

SCENARIO("Remove Voyage") {
    GIVEN("an existing Voyage") {
        WHEN("the entity is removed") {
            // cmd_service.remove(id);

            THEN("it should no longer be findable") {
                // auto found = query_service.find_by_id(id);
                // CHECK(!found.has_value());
            }
        }
    }
}

SCENARIO("Add child PilotAssignment to Voyage") {
    GIVEN("an existing Voyage aggregate root") {
        WHEN("a PilotAssignment child is added") {
            // auto result = cmd_service.add_child(parent_id, child);

            THEN("the child should be part of the aggregate") {
                // CHECK(result.has_value());
            }
        }
    }
}

SCENARIO("Add child TugBooking to Voyage") {
    GIVEN("an existing Voyage aggregate root") {
        WHEN("a TugBooking child is added") {
            // auto result = cmd_service.add_child(parent_id, child);

            THEN("the child should be part of the aggregate") {
                // CHECK(result.has_value());
            }
        }
    }
}
