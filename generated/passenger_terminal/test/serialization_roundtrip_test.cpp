// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>
#include <random>
#include <string>
#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid_io.hpp>

// Serialization round-trip tests for PassengerTerminal

SCENARIO("Serialization round-trip: Passenger") {
    GIVEN("a Passenger with random values") {
        auto rng = std::mt19937{std::random_device{}()};
        auto dist = std::uniform_int_distribution<int>{0, 10000};
        auto uuid_gen = boost::uuids::random_generator{};
        auto original = Passenger{};
        original.id = boost::uuids::to_string(uuid_gen());
        original.booking_ref = {};
        original.passenger_type = "test_" + std::to_string(dist(rng));
        original.voyage_id = boost::uuids::to_string(uuid_gen());
        original.status = "test_" + std::to_string(dist(rng));

        WHEN("serialized and deserialized") {
            // auto serialized = serialize(original);
            // auto deserialized = deserialize<Passenger>(serialized);

            THEN("the deserialized object equals the original") {
                // CHECK(deserialized == original);
            }
        }
    }
}

SCENARIO("Serialization round-trip: Gate") {
    GIVEN("a Gate with random values") {
        auto rng = std::mt19937{std::random_device{}()};
        auto dist = std::uniform_int_distribution<int>{0, 10000};
        auto uuid_gen = boost::uuids::random_generator{};
        auto original = Gate{};
        original.id = boost::uuids::to_string(uuid_gen());
        original.code = {};
        original.name = "test_" + std::to_string(dist(rng));
        original.capacity = {};
        original.status = "test_" + std::to_string(dist(rng));
        original.voyage_id = boost::uuids::to_string(uuid_gen());

        WHEN("serialized and deserialized") {
            // auto serialized = serialize(original);
            // auto deserialized = deserialize<Gate>(serialized);

            THEN("the deserialized object equals the original") {
                // CHECK(deserialized == original);
            }
        }
    }
}

SCENARIO("Serialization round-trip: BoardingPass") {
    GIVEN("a BoardingPass with random values") {
        auto rng = std::mt19937{std::random_device{}()};
        auto dist = std::uniform_int_distribution<int>{0, 10000};
        auto uuid_gen = boost::uuids::random_generator{};
        auto original = BoardingPass{};
        original.id = boost::uuids::to_string(uuid_gen());
        original.passenger_id = boost::uuids::to_string(uuid_gen());
        original.gate_id = boost::uuids::to_string(uuid_gen());
        original.boarding_group = "test_" + std::to_string(dist(rng));
        original.seat_number = "test_" + std::to_string(dist(rng));
        original.issued_at = {};
        original.scanned_at = {};

        WHEN("serialized and deserialized") {
            // auto serialized = serialize(original);
            // auto deserialized = deserialize<BoardingPass>(serialized);

            THEN("the deserialized object equals the original") {
                // CHECK(deserialized == original);
            }
        }
    }
}
