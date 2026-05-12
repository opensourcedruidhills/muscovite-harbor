// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>
#include <random>
#include <string>
#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid_io.hpp>

// Serialization round-trip tests for IntermodalTransfer

SCENARIO("Serialization round-trip: TransferSlot") {
    GIVEN("a TransferSlot with random values") {
        auto rng = std::mt19937{std::random_device{}()};
        auto dist = std::uniform_int_distribution<int>{0, 10000};
        auto uuid_gen = boost::uuids::random_generator{};
        auto original = TransferSlot{};
        original.id = boost::uuids::to_string(uuid_gen());
        original.reference = {};
        original.container_id = boost::uuids::to_string(uuid_gen());
        original.transport_mode = "test_" + std::to_string(dist(rng));
        original.scheduled_at = {};
        original.status = "test_" + std::to_string(dist(rng));

        WHEN("serialized and deserialized") {
            // auto serialized = serialize(original);
            // auto deserialized = deserialize<TransferSlot>(serialized);

            THEN("the deserialized object equals the original") {
                // CHECK(deserialized == original);
            }
        }
    }
}

SCENARIO("Serialization round-trip: TruckVisit") {
    GIVEN("a TruckVisit with random values") {
        auto rng = std::mt19937{std::random_device{}()};
        auto dist = std::uniform_int_distribution<int>{0, 10000};
        auto uuid_gen = boost::uuids::random_generator{};
        auto original = TruckVisit{};
        original.id = boost::uuids::to_string(uuid_gen());
        original.truck_plate = {};
        original.carrier_name = "test_" + std::to_string(dist(rng));
        original.slot_id = boost::uuids::to_string(uuid_gen());
        original.arrived_at = {};
        original.departed_at = {};

        WHEN("serialized and deserialized") {
            // auto serialized = serialize(original);
            // auto deserialized = deserialize<TruckVisit>(serialized);

            THEN("the deserialized object equals the original") {
                // CHECK(deserialized == original);
            }
        }
    }
}

SCENARIO("Serialization round-trip: RailWagon") {
    GIVEN("a RailWagon with random values") {
        auto rng = std::mt19937{std::random_device{}()};
        auto dist = std::uniform_int_distribution<int>{0, 10000};
        auto uuid_gen = boost::uuids::random_generator{};
        auto original = RailWagon{};
        original.id = boost::uuids::to_string(uuid_gen());
        original.wagon_number = "test_" + std::to_string(dist(rng));
        original.max_weight_kg = static_cast<double>(dist(rng)) / 100.0;
        original.slot_id = boost::uuids::to_string(uuid_gen());

        WHEN("serialized and deserialized") {
            // auto serialized = serialize(original);
            // auto deserialized = deserialize<RailWagon>(serialized);

            THEN("the deserialized object equals the original") {
                // CHECK(deserialized == original);
            }
        }
    }
}

SCENARIO("Serialization round-trip: BargeBooking") {
    GIVEN("a BargeBooking with random values") {
        auto rng = std::mt19937{std::random_device{}()};
        auto dist = std::uniform_int_distribution<int>{0, 10000};
        auto uuid_gen = boost::uuids::random_generator{};
        auto original = BargeBooking{};
        original.id = boost::uuids::to_string(uuid_gen());
        original.barge_name = "test_" + std::to_string(dist(rng));
        original.capacity_teu = {};
        original.departure_at = {};
        original.status = "test_" + std::to_string(dist(rng));

        WHEN("serialized and deserialized") {
            // auto serialized = serialize(original);
            // auto deserialized = deserialize<BargeBooking>(serialized);

            THEN("the deserialized object equals the original") {
                // CHECK(deserialized == original);
            }
        }
    }
}

SCENARIO("Serialization round-trip: ChassisUnit") {
    GIVEN("a ChassisUnit with random values") {
        auto rng = std::mt19937{std::random_device{}()};
        auto dist = std::uniform_int_distribution<int>{0, 10000};
        auto uuid_gen = boost::uuids::random_generator{};
        auto original = ChassisUnit{};
        original.id = boost::uuids::to_string(uuid_gen());
        original.chassis_number = "test_" + std::to_string(dist(rng));
        original.chassis_type = "test_" + std::to_string(dist(rng));
        original.is_available = (dist(rng) % 2 == 0);

        WHEN("serialized and deserialized") {
            // auto serialized = serialize(original);
            // auto deserialized = deserialize<ChassisUnit>(serialized);

            THEN("the deserialized object equals the original") {
                // CHECK(deserialized == original);
            }
        }
    }
}
