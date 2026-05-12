#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>
#include <optional>

// Forward declaration of repository for testing
namespace cargo_operations { class CraneRepository; }

namespace cargo_operations::test {

SCENARIO("Crane CRUD round-trip") {
    GIVEN("a mock repository and a seed Crane") {
        // Mock repository - in real use, this would be the generated repository
        struct MockCraneRepository : public CraneRepository {
            Crane stored_entity;
            bool removed = false;

            std::optional<Crane> find_by_id(const Crane::Id&) override {
                return stored_entity;
            }

            void save(const Crane& e) override {
                stored_entity = e;
            }

            void remove(const Crane::Id&) override {
                removed = true;
                stored_entity = {};
            }

            auto find_all() -> Cranes override {
                return {stored_entity};
            }
        }; 

        auto entity = make_seed_crane();
        auto repo = MockCraneRepository{};

        WHEN("entity is saved") {
            repo.save(entity);

            THEN("it can be retrieved by id") {
                auto found = repo.find_by_id(entity.id);
                REQUIRE(found.has_value());
                // assert_crane_equals(*found, entity);
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

} // namespace cargo_operations::test
