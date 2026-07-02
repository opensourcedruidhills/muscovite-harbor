#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>
#include <optional>

// Forward declaration of repository for testing
namespace harbour_control { class SafetyZoneRepository; }

namespace harbour_control::test {

SCENARIO("SafetyZone CRUD round-trip") {
    GIVEN("a mock repository and a seed SafetyZone") {
        // Mock repository - in real use, this would be the generated repository
        struct MockSafetyZoneRepository : public SafetyZoneRepository {
            SafetyZone stored_entity;
            bool removed = false;

            std::optional<SafetyZone> find_by_id(const SafetyZone::Id&) override {
                return stored_entity;
            }

            void save(const SafetyZone& e) override {
                stored_entity = e;
            }

            void remove(const SafetyZone::Id&) override {
                removed = true;
                stored_entity = {};
            }

            auto find_all() -> SafetyZones override {
                return {stored_entity};
            }
        }; 

        auto entity = make_seed_safety_zone();
        auto repo = MockSafetyZoneRepository{};

        WHEN("entity is saved") {
            repo.save(entity);

            THEN("it can be retrieved by id") {
                auto found = repo.find_by_id(entity.id);
                REQUIRE(found.has_value());
                // assert_safety_zone_equals(*found, entity);
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

} // namespace harbour_control::test
