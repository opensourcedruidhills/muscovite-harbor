#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>
#include <optional>

// Forward declaration of repository for testing
namespace spatial { class RegionRepository; }

namespace spatial::test {

SCENARIO("Region CRUD round-trip") {
    GIVEN("a mock repository and a seed Region") {
        // Mock repository - in real use, this would be the generated repository
        struct MockRegionRepository : public RegionRepository {
            Region stored_entity;
            bool removed = false;

            std::optional<Region> find_by_id(const Region::Id&) override {
                return stored_entity;
            }

            void save(const Region& e) override {
                stored_entity = e;
            }

            void remove(const Region::Id&) override {
                removed = true;
                stored_entity = {};
            }

            auto find_all() -> Regions override {
                return {stored_entity};
            }
        }; 

        auto entity = make_seed_region();
        auto repo = MockRegionRepository{};

        WHEN("entity is saved") {
            repo.save(entity);

            THEN("it can be retrieved by id") {
                auto found = repo.find_by_id(entity.id);
                REQUIRE(found.has_value());
                // assert_region_equals(*found, entity);
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

} // namespace spatial::test
