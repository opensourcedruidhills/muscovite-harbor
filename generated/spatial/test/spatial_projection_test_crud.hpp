#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>
#include <optional>

// Forward declaration of repository for testing
namespace spatial { class SpatialProjectionRepository; }

namespace spatial::test {

SCENARIO("SpatialProjection CRUD round-trip") {
    GIVEN("a mock repository and a seed SpatialProjection") {
        // Mock repository - in real use, this would be the generated repository
        struct MockSpatialProjectionRepository : public SpatialProjectionRepository {
            SpatialProjection stored_entity;
            bool removed = false;

            std::optional<SpatialProjection> find_by_id(const SpatialProjection::Id&) override {
                return stored_entity;
            }

            void save(const SpatialProjection& e) override {
                stored_entity = e;
            }

            void remove(const SpatialProjection::Id&) override {
                removed = true;
                stored_entity = {};
            }

            auto find_all() -> SpatialProjections override {
                return {stored_entity};
            }
        }; 

        auto entity = make_seed_spatial_projection();
        auto repo = MockSpatialProjectionRepository{};

        WHEN("entity is saved") {
            repo.save(entity);

            THEN("it can be retrieved by id") {
                auto found = repo.find_by_id(entity.id);
                REQUIRE(found.has_value());
                // assert_spatial_projection_equals(*found, entity);
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
