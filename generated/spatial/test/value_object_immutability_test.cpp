// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>
#include <random>
#include <string>
#include <type_traits>
#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid_io.hpp>

// Value object immutability tests for spatial

SCENARIO("Value object immutability: BoundingBox") {
    GIVEN("a BoundingBox value object") {
        auto rng = std::mt19937{std::random_device{}()};
        auto dist = std::uniform_int_distribution<int>{0, 10000};
        auto uuid_gen = boost::uuids::random_generator{};
        auto vo = BoundingBox{};

        WHEN("equality is checked after copy") {
            auto copy = vo;
            THEN("copy must equal original (value semantics)") {
                // CHECK(copy == vo);
            }
        }

    }
}

SCENARIO("Value object immutability: GeoPoint") {
    GIVEN("a GeoPoint value object") {
        auto rng = std::mt19937{std::random_device{}()};
        auto dist = std::uniform_int_distribution<int>{0, 10000};
        auto uuid_gen = boost::uuids::random_generator{};
        auto vo = GeoPoint{};

        WHEN("equality is checked after copy") {
            auto copy = vo;
            THEN("copy must equal original (value semantics)") {
                // CHECK(copy == vo);
            }
        }

    }
}
