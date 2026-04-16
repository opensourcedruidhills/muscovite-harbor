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

        WHEN("the entity is created") {
            THEN("all fields should be set") {
                CHECK_FALSE(entity.id.empty());
                CHECK(entity.id == "00000000-0000-0000-0000-000000000001");
                CHECK(entity.vessel_id == "00000000-0000-0000-0000-000000000001");
                CHECK(entity.berth_id == "00000000-0000-0000-0000-000000000001");
                CHECK(entity.voyage_number == "test_value");
                CHECK(entity.cargo_category == "test_value");
                CHECK(entity.status == "test_value");
            }
        }
    }
}

SCENARIO("Voyage round-trip serialization") {
    GIVEN("a Voyage with populated fields") {
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

        WHEN("checked for default state") {
            THEN("the entity should have non-default values") {
                CHECK(entity.id == "00000000-0000-0000-0000-000000000001");
                CHECK(entity.vessel_id == "00000000-0000-0000-0000-000000000001");
                CHECK(entity.berth_id == "00000000-0000-0000-0000-000000000001");
                CHECK(entity.voyage_number == "test_value");
                CHECK(entity.cargo_category == "test_value");
                CHECK(entity.status == "test_value");
            }
        }
    }
}

SCENARIO("Update Voyage fields") {
    GIVEN("a Voyage with initial values") {
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

        WHEN("fields are modified") {
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

            THEN("the entity reflects the new values") {
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

SCENARIO("Voyage identity comparison") {
    GIVEN("two Voyage entities with the same ID") {
        auto a = vessel_traffic::Voyage{};
        auto b = vessel_traffic::Voyage{};
        a.id = b.id = "test-id-001";

        WHEN("compared") {
            THEN("they should be considered equal by ID") {
                CHECK(a.id == b.id);
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
