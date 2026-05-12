// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>
#include <random>
#include <string>
#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid_io.hpp>

// Serialization round-trip tests for CargoDecomposition

SCENARIO("Serialization round-trip: Pallet") {
    GIVEN("a Pallet with random values") {
        auto rng = std::mt19937{std::random_device{}()};
        auto dist = std::uniform_int_distribution<int>{0, 10000};
        auto uuid_gen = boost::uuids::random_generator{};
        auto original = Pallet{};
        original.id = boost::uuids::to_string(uuid_gen());
        original.pallet_id = {};
        original.container_id = boost::uuids::to_string(uuid_gen());
        original.weight_kg = static_cast<double>(dist(rng)) / 100.0;
        original.length_cm = static_cast<double>(dist(rng)) / 100.0;
        original.width_cm = static_cast<double>(dist(rng)) / 100.0;
        original.height_cm = static_cast<double>(dist(rng)) / 100.0;
        original.hs_code = {};

        WHEN("serialized and deserialized") {
            // auto serialized = serialize(original);
            // auto deserialized = deserialize<Pallet>(serialized);

            THEN("the deserialized object equals the original") {
                // CHECK(deserialized == original);
            }
        }
    }
}

SCENARIO("Serialization round-trip: Parcel") {
    GIVEN("a Parcel with random values") {
        auto rng = std::mt19937{std::random_device{}()};
        auto dist = std::uniform_int_distribution<int>{0, 10000};
        auto uuid_gen = boost::uuids::random_generator{};
        auto original = Parcel{};
        original.id = boost::uuids::to_string(uuid_gen());
        original.tracking_number = {};
        original.pallet_id = boost::uuids::to_string(uuid_gen());
        original.weight_kg = static_cast<double>(dist(rng)) / 100.0;
        original.hs_code = {};
        original.description = "test_" + std::to_string(dist(rng));

        WHEN("serialized and deserialized") {
            // auto serialized = serialize(original);
            // auto deserialized = deserialize<Parcel>(serialized);

            THEN("the deserialized object equals the original") {
                // CHECK(deserialized == original);
            }
        }
    }
}

SCENARIO("Serialization round-trip: DeliveryUnit") {
    GIVEN("a DeliveryUnit with random values") {
        auto rng = std::mt19937{std::random_device{}()};
        auto dist = std::uniform_int_distribution<int>{0, 10000};
        auto uuid_gen = boost::uuids::random_generator{};
        auto original = DeliveryUnit{};
        original.id = boost::uuids::to_string(uuid_gen());
        original.tracking_number = {};
        original.destination = "test_" + std::to_string(dist(rng));
        original.carrier = "test_" + std::to_string(dist(rng));
        original.dispatched_at = {};

        WHEN("serialized and deserialized") {
            // auto serialized = serialize(original);
            // auto deserialized = deserialize<DeliveryUnit>(serialized);

            THEN("the deserialized object equals the original") {
                // CHECK(deserialized == original);
            }
        }
    }
}

SCENARIO("Serialization round-trip: BreakBulkItem") {
    GIVEN("a BreakBulkItem with random values") {
        auto rng = std::mt19937{std::random_device{}()};
        auto dist = std::uniform_int_distribution<int>{0, 10000};
        auto uuid_gen = boost::uuids::random_generator{};
        auto original = BreakBulkItem{};
        original.id = boost::uuids::to_string(uuid_gen());
        original.container_id = boost::uuids::to_string(uuid_gen());
        original.item_type = "test_" + std::to_string(dist(rng));
        original.weight_kg = static_cast<double>(dist(rng)) / 100.0;
        original.requires_crane = (dist(rng) % 2 == 0);

        WHEN("serialized and deserialized") {
            // auto serialized = serialize(original);
            // auto deserialized = deserialize<BreakBulkItem>(serialized);

            THEN("the deserialized object equals the original") {
                // CHECK(deserialized == original);
            }
        }
    }
}
