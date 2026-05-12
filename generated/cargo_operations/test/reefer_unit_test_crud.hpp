#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>
#include <optional>

// Forward declaration of repository for testing
namespace cargo_operations { class ReeferUnitRepository; }

namespace cargo_operations::test {

SCENARIO("ReeferUnit CRUD round-trip") {
    GIVEN("a mock repository and a seed ReeferUnit") {
        // Mock repository - in real use, this would be the generated repository
        struct MockReeferUnitRepository : public ReeferUnitRepository {
            ReeferUnit stored_entity;
            bool removed = false;

            std::optional<ReeferUnit> find_by_id(const ReeferUnit::Id&) override {
                return stored_entity;
            }

            void save(const ReeferUnit& e) override {
                stored_entity = e;
            }

            void remove(const ReeferUnit::Id&) override {
                removed = true;
                stored_entity = {};
            }

            auto find_all() -> ReeferUnits override {
                return {stored_entity};
            }
        }; 

        auto entity = make_seed_reefer_unit();
        auto repo = MockReeferUnitRepository{};

        WHEN("entity is saved") {
            repo.save(entity);

            THEN("it can be retrieved by id") {
                auto found = repo.find_by_id(entity.id);
                REQUIRE(found.has_value());
                // assert_reefer_unit_equals(*found, entity);
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
