// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>
#include <random>
#include <string>
#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid_io.hpp>

// Serialization round-trip tests for CargoOperations

SCENARIO("Serialization round-trip: Container") {
    GIVEN("a Container with random values") {
        auto rng = std::mt19937{std::random_device{}()};
        auto dist = std::uniform_int_distribution<int>{0, 10000};
        auto uuid_gen = boost::uuids::random_generator{};
        auto original = Container{};
        original.id = boost::uuids::to_string(uuid_gen());
        original.container_number = {};
        original.size_category = "test_" + std::to_string(dist(rng));
        original.hazmat_class = "test_" + std::to_string(dist(rng));
        original.voyage_id = boost::uuids::to_string(uuid_gen());
        original.yard_slot_id = boost::uuids::to_string(uuid_gen());
        original.status = "test_" + std::to_string(dist(rng));

        WHEN("serialized and deserialized") {
            // auto serialized = serialize(original);
            // auto deserialized = deserialize<Container>(serialized);

            THEN("the deserialized object equals the original") {
                // CHECK(deserialized == original);
            }
        }
    }
}

SCENARIO("Serialization round-trip: YardSlot") {
    GIVEN("a YardSlot with random values") {
        auto rng = std::mt19937{std::random_device{}()};
        auto dist = std::uniform_int_distribution<int>{0, 10000};
        auto uuid_gen = boost::uuids::random_generator{};
        auto original = YardSlot{};
        original.id = boost::uuids::to_string(uuid_gen());
        original.code = {};
        original.max_weight_kg = static_cast<double>(dist(rng)) / 100.0;
        original.max_tier = {};
        original.has_power = (dist(rng) % 2 == 0);
        original.is_occupied = (dist(rng) % 2 == 0);

        WHEN("serialized and deserialized") {
            // auto serialized = serialize(original);
            // auto deserialized = deserialize<YardSlot>(serialized);

            THEN("the deserialized object equals the original") {
                // CHECK(deserialized == original);
            }
        }
    }
}

SCENARIO("Serialization round-trip: Crane") {
    GIVEN("a Crane with random values") {
        auto rng = std::mt19937{std::random_device{}()};
        auto dist = std::uniform_int_distribution<int>{0, 10000};
        auto uuid_gen = boost::uuids::random_generator{};
        auto original = Crane{};
        original.id = boost::uuids::to_string(uuid_gen());
        original.name = "test_" + std::to_string(dist(rng));
        original.crane_type = "test_" + std::to_string(dist(rng));
        original.max_lift_kg = static_cast<double>(dist(rng)) / 100.0;
        original.is_active = (dist(rng) % 2 == 0);

        WHEN("serialized and deserialized") {
            // auto serialized = serialize(original);
            // auto deserialized = deserialize<Crane>(serialized);

            THEN("the deserialized object equals the original") {
                // CHECK(deserialized == original);
            }
        }
    }
}

SCENARIO("Serialization round-trip: ReeferUnit") {
    GIVEN("a ReeferUnit with random values") {
        auto rng = std::mt19937{std::random_device{}()};
        auto dist = std::uniform_int_distribution<int>{0, 10000};
        auto uuid_gen = boost::uuids::random_generator{};
        auto original = ReeferUnit{};
        original.id = boost::uuids::to_string(uuid_gen());
        original.container_id = boost::uuids::to_string(uuid_gen());
        original.target_temp_c = static_cast<double>(dist(rng)) / 100.0;
        original.current_temp_c = static_cast<double>(dist(rng)) / 100.0;
        original.is_powered = (dist(rng) % 2 == 0);

        WHEN("serialized and deserialized") {
            // auto serialized = serialize(original);
            // auto deserialized = deserialize<ReeferUnit>(serialized);

            THEN("the deserialized object equals the original") {
                // CHECK(deserialized == original);
            }
        }
    }
}

SCENARIO("Serialization round-trip: LoadPlan") {
    GIVEN("a LoadPlan with random values") {
        auto rng = std::mt19937{std::random_device{}()};
        auto dist = std::uniform_int_distribution<int>{0, 10000};
        auto uuid_gen = boost::uuids::random_generator{};
        auto original = LoadPlan{};
        original.id = boost::uuids::to_string(uuid_gen());
        original.voyage_id = boost::uuids::to_string(uuid_gen());
        original.created_at = {};
        original.status = "test_" + std::to_string(dist(rng));

        WHEN("serialized and deserialized") {
            // auto serialized = serialize(original);
            // auto deserialized = deserialize<LoadPlan>(serialized);

            THEN("the deserialized object equals the original") {
                // CHECK(deserialized == original);
            }
        }
    }
}

SCENARIO("Serialization round-trip: DischargeSequence") {
    GIVEN("a DischargeSequence with random values") {
        auto rng = std::mt19937{std::random_device{}()};
        auto dist = std::uniform_int_distribution<int>{0, 10000};
        auto uuid_gen = boost::uuids::random_generator{};
        auto original = DischargeSequence{};
        original.id = boost::uuids::to_string(uuid_gen());
        original.load_plan_id = boost::uuids::to_string(uuid_gen());
        original.container_id = boost::uuids::to_string(uuid_gen());
        original.sequence_order = {};
        original.crane_id = boost::uuids::to_string(uuid_gen());

        WHEN("serialized and deserialized") {
            // auto serialized = serialize(original);
            // auto deserialized = deserialize<DischargeSequence>(serialized);

            THEN("the deserialized object equals the original") {
                // CHECK(deserialized == original);
            }
        }
    }
}
