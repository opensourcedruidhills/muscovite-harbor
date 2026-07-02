#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>
#include <optional>

// Forward declaration of repository for testing
namespace cargo_operations { class LoadPlanRepository; }

namespace cargo_operations::test {

SCENARIO("LoadPlan CRUD round-trip") {
    GIVEN("a mock repository and a seed LoadPlan") {
        // Mock repository - in real use, this would be the generated repository
        struct MockLoadPlanRepository : public LoadPlanRepository {
            LoadPlan stored_entity;
            bool removed = false;

            std::optional<LoadPlan> find_by_id(const LoadPlan::Id&) override {
                return stored_entity;
            }

            void save(const LoadPlan& e) override {
                stored_entity = e;
            }

            void remove(const LoadPlan::Id&) override {
                removed = true;
                stored_entity = {};
            }

            auto find_all() -> LoadPlans override {
                return {stored_entity};
            }
        }; 

        auto entity = make_seed_load_plan();
        auto repo = MockLoadPlanRepository{};

        WHEN("entity is saved") {
            repo.save(entity);

            THEN("it can be retrieved by id") {
                auto found = repo.find_by_id(entity.id);
                REQUIRE(found.has_value());
                // assert_load_plan_equals(*found, entity);
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
