// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>
#include <random>
#include <string>
#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid_io.hpp>

// Serialization round-trip tests for VesselTraffic

SCENARIO("Serialization round-trip: Vessel") {
    GIVEN("a Vessel with random values") {
        auto rng = std::mt19937{std::random_device{}()};
        auto dist = std::uniform_int_distribution<int>{0, 10000};
        auto uuid_gen = boost::uuids::random_generator{};
        auto original = Vessel{};
        original.id = boost::uuids::to_string(uuid_gen());
        original.imo_number = {};
        original.mmsi = {};
        original.call_sign = {};
        original.name = "test_" + std::to_string(dist(rng));
        original.vessel_type = "test_" + std::to_string(dist(rng));
        original.flag_state = "test_" + std::to_string(dist(rng));
        original.is_active = (dist(rng) % 2 == 0);

        WHEN("serialized and deserialized") {
            // auto serialized = serialize(original);
            // auto deserialized = deserialize<Vessel>(serialized);

            THEN("the deserialized object equals the original") {
                // CHECK(deserialized == original);
            }
        }
    }
}

SCENARIO("Serialization round-trip: Berth") {
    GIVEN("a Berth with random values") {
        auto rng = std::mt19937{std::random_device{}()};
        auto dist = std::uniform_int_distribution<int>{0, 10000};
        auto uuid_gen = boost::uuids::random_generator{};
        auto original = Berth{};
        original.id = boost::uuids::to_string(uuid_gen());
        original.code = {};
        original.name = "test_" + std::to_string(dist(rng));
        original.max_loa_metres = static_cast<double>(dist(rng)) / 100.0;
        original.max_draft_metres = static_cast<double>(dist(rng)) / 100.0;
        original.max_beam_metres = static_cast<double>(dist(rng)) / 100.0;
        original.has_crane_access = (dist(rng) % 2 == 0);
        original.has_reefer_plugs = (dist(rng) % 2 == 0);
        original.is_active = (dist(rng) % 2 == 0);

        WHEN("serialized and deserialized") {
            // auto serialized = serialize(original);
            // auto deserialized = deserialize<Berth>(serialized);

            THEN("the deserialized object equals the original") {
                // CHECK(deserialized == original);
            }
        }
    }
}

SCENARIO("Serialization round-trip: Voyage") {
    GIVEN("a Voyage with random values") {
        auto rng = std::mt19937{std::random_device{}()};
        auto dist = std::uniform_int_distribution<int>{0, 10000};
        auto uuid_gen = boost::uuids::random_generator{};
        auto original = Voyage{};
        original.id = boost::uuids::to_string(uuid_gen());
        original.vessel_id = boost::uuids::to_string(uuid_gen());
        original.berth_id = boost::uuids::to_string(uuid_gen());
        original.voyage_number = "test_" + std::to_string(dist(rng));
        original.eta = {};
        original.ata = {};
        original.etd = {};
        original.atd = {};
        original.cargo_category = "test_" + std::to_string(dist(rng));
        original.status = "test_" + std::to_string(dist(rng));

        WHEN("serialized and deserialized") {
            // auto serialized = serialize(original);
            // auto deserialized = deserialize<Voyage>(serialized);

            THEN("the deserialized object equals the original") {
                // CHECK(deserialized == original);
            }
        }
    }
}

SCENARIO("Serialization round-trip: PilotAssignment") {
    GIVEN("a PilotAssignment with random values") {
        auto rng = std::mt19937{std::random_device{}()};
        auto dist = std::uniform_int_distribution<int>{0, 10000};
        auto uuid_gen = boost::uuids::random_generator{};
        auto original = PilotAssignment{};
        original.id = boost::uuids::to_string(uuid_gen());
        original.voyage_id = boost::uuids::to_string(uuid_gen());
        original.pilot_name = "test_" + std::to_string(dist(rng));
        original.pilot_zone = "test_" + std::to_string(dist(rng));
        original.boarding_time = {};
        original.disembark_time = {};

        WHEN("serialized and deserialized") {
            // auto serialized = serialize(original);
            // auto deserialized = deserialize<PilotAssignment>(serialized);

            THEN("the deserialized object equals the original") {
                // CHECK(deserialized == original);
            }
        }
    }
}

SCENARIO("Serialization round-trip: TugBooking") {
    GIVEN("a TugBooking with random values") {
        auto rng = std::mt19937{std::random_device{}()};
        auto dist = std::uniform_int_distribution<int>{0, 10000};
        auto uuid_gen = boost::uuids::random_generator{};
        auto original = TugBooking{};
        original.id = boost::uuids::to_string(uuid_gen());
        original.voyage_id = boost::uuids::to_string(uuid_gen());
        original.tug_name = "test_" + std::to_string(dist(rng));
        original.bollard_pull_t = static_cast<double>(dist(rng)) / 100.0;
        original.is_confirmed = (dist(rng) % 2 == 0);

        WHEN("serialized and deserialized") {
            // auto serialized = serialize(original);
            // auto deserialized = deserialize<TugBooking>(serialized);

            THEN("the deserialized object equals the original") {
                // CHECK(deserialized == original);
            }
        }
    }
}

SCENARIO("Serialization round-trip: TideWindow") {
    GIVEN("a TideWindow with random values") {
        auto rng = std::mt19937{std::random_device{}()};
        auto dist = std::uniform_int_distribution<int>{0, 10000};
        auto uuid_gen = boost::uuids::random_generator{};
        auto original = TideWindow{};
        original.id = boost::uuids::to_string(uuid_gen());
        original.berth_id = boost::uuids::to_string(uuid_gen());
        original.tide_height_metres = static_cast<double>(dist(rng)) / 100.0;
        original.available_draft = static_cast<double>(dist(rng)) / 100.0;

        WHEN("serialized and deserialized") {
            // auto serialized = serialize(original);
            // auto deserialized = deserialize<TideWindow>(serialized);

            THEN("the deserialized object equals the original") {
                // CHECK(deserialized == original);
            }
        }
    }
}
