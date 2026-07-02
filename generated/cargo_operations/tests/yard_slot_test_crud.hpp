#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>
#include <optional>

// Forward declaration of repository for testing
namespace cargo_operations { class YardSlotRepository; }

namespace cargo_operations::test {

SCENARIO("YardSlot CRUD round-trip") {
    GIVEN("a mock repository and a seed YardSlot") {
        // Mock repository - in real use, this would be the generated repository
        struct MockYardSlotRepository : public YardSlotRepository {
            YardSlot stored_entity;
            bool removed = false;

            std::optional<YardSlot> find_by_id(const YardSlot::Id&) override {
                return stored_entity;
            }

            void save(const YardSlot& e) override {
                stored_entity = e;
            }

            void remove(const YardSlot::Id&) override {
                removed = true;
                stored_entity = {};
            }

            auto find_all() -> YardSlots override {
                return {stored_entity};
            }
        }; 

        auto entity = make_seed_yard_slot();
        auto repo = MockYardSlotRepository{};

        WHEN("entity is saved") {
            repo.save(entity);

            THEN("it can be retrieved by id") {
                auto found = repo.find_by_id(entity.id);
                REQUIRE(found.has_value());
                // assert_yard_slot_equals(*found, entity);
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
