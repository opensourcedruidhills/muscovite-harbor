// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>
#include <random>
#include <string>
#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid_io.hpp>

// Serialization round-trip tests for HarbourControl

SCENARIO("Serialization round-trip: SafetyZone") {
    GIVEN("a SafetyZone with random values") {
        auto rng = std::mt19937{std::random_device{}()};
        auto dist = std::uniform_int_distribution<int>{0, 10000};
        auto uuid_gen = boost::uuids::random_generator{};
        auto original = SafetyZone{};
        original.id = boost::uuids::to_string(uuid_gen());
        original.zone_code = {};
        original.zone_name = "test_" + std::to_string(dist(rng));
        original.security_level = "test_" + std::to_string(dist(rng));
        original.max_hazmat_class = {};
        original.is_restricted = (dist(rng) % 2 == 0);

        WHEN("serialized and deserialized") {
            // auto serialized = serialize(original);
            // auto deserialized = deserialize<SafetyZone>(serialized);

            THEN("the deserialized object equals the original") {
                // CHECK(deserialized == original);
            }
        }
    }
}

SCENARIO("Serialization round-trip: HazmatPermit") {
    GIVEN("a HazmatPermit with random values") {
        auto rng = std::mt19937{std::random_device{}()};
        auto dist = std::uniform_int_distribution<int>{0, 10000};
        auto uuid_gen = boost::uuids::random_generator{};
        auto original = HazmatPermit{};
        original.id = boost::uuids::to_string(uuid_gen());
        original.permit_number = {};
        original.vessel_id = boost::uuids::to_string(uuid_gen());
        original.imo_class = {};
        original.quantity_kg = static_cast<double>(dist(rng)) / 100.0;
        original.approved = (dist(rng) % 2 == 0);
        original.valid_from = {};
        original.valid_until = {};

        WHEN("serialized and deserialized") {
            // auto serialized = serialize(original);
            // auto deserialized = deserialize<HazmatPermit>(serialized);

            THEN("the deserialized object equals the original") {
                // CHECK(deserialized == original);
            }
        }
    }
}

SCENARIO("Serialization round-trip: InvoiceLine") {
    GIVEN("a InvoiceLine with random values") {
        auto rng = std::mt19937{std::random_device{}()};
        auto dist = std::uniform_int_distribution<int>{0, 10000};
        auto uuid_gen = boost::uuids::random_generator{};
        auto original = InvoiceLine{};
        original.id = boost::uuids::to_string(uuid_gen());
        original.vessel_id = boost::uuids::to_string(uuid_gen());
        original.service_type = "test_" + std::to_string(dist(rng));
        original.amount = static_cast<double>(dist(rng)) / 100.0;
        original.currency = "test_" + std::to_string(dist(rng));
        original.issued_at = {};

        WHEN("serialized and deserialized") {
            // auto serialized = serialize(original);
            // auto deserialized = deserialize<InvoiceLine>(serialized);

            THEN("the deserialized object equals the original") {
                // CHECK(deserialized == original);
            }
        }
    }
}

SCENARIO("Serialization round-trip: PortCall") {
    GIVEN("a PortCall with random values") {
        auto rng = std::mt19937{std::random_device{}()};
        auto dist = std::uniform_int_distribution<int>{0, 10000};
        auto uuid_gen = boost::uuids::random_generator{};
        auto original = PortCall{};
        original.id = boost::uuids::to_string(uuid_gen());
        original.vessel_name = "test_" + std::to_string(dist(rng));
        original.imo_number = "test_" + std::to_string(dist(rng));
        original.berth_code = "test_" + std::to_string(dist(rng));
        original.arrival_time = {};
        original.departure_time = {};
        original.container_count = {};
        original.hazmat_permits = {};
        original.total_billed = static_cast<double>(dist(rng)) / 100.0;

        WHEN("serialized and deserialized") {
            // auto serialized = serialize(original);
            // auto deserialized = deserialize<PortCall>(serialized);

            THEN("the deserialized object equals the original") {
                // CHECK(deserialized == original);
            }
        }
    }
}
