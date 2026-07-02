#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>
#include <optional>

// Forward declaration of repository for testing
namespace intermodal_transfer { class ChassisUnitRepository; }

namespace intermodal_transfer::test {

SCENARIO("ChassisUnit CRUD round-trip") {
    GIVEN("a mock repository and a seed ChassisUnit") {
        // Mock repository - in real use, this would be the generated repository
        struct MockChassisUnitRepository : public ChassisUnitRepository {
            ChassisUnit stored_entity;
            bool removed = false;

            std::optional<ChassisUnit> find_by_id(const ChassisUnit::Id&) override {
                return stored_entity;
            }

            void save(const ChassisUnit& e) override {
                stored_entity = e;
            }

            void remove(const ChassisUnit::Id&) override {
                removed = true;
                stored_entity = {};
            }

            auto find_all() -> ChassisUnits override {
                return {stored_entity};
            }
        }; 

        auto entity = make_seed_chassis_unit();
        auto repo = MockChassisUnitRepository{};

        WHEN("entity is saved") {
            repo.save(entity);

            THEN("it can be retrieved by id") {
                auto found = repo.find_by_id(entity.id);
                REQUIRE(found.has_value());
                // assert_chassis_unit_equals(*found, entity);
            }
        }

        WHEN("entity is removed") {
            repo.remove(entity.id);

            THEN("it is no longer retrievable") {
                auto found = repo.find_by_id(entity.id);
                CHECK_FALSE(found.has_value());
            }
        }
    }
}

} // namespace intermodal_transfer::test
