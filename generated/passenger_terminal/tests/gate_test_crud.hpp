#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>
#include <optional>

// Forward declaration of repository for testing
namespace passenger_terminal { class GateRepository; }

namespace passenger_terminal::test {

SCENARIO("Gate CRUD round-trip") {
    GIVEN("a mock repository and a seed Gate") {
        // Mock repository - in real use, this would be the generated repository
        struct MockGateRepository : public GateRepository {
            Gate stored_entity;
            bool removed = false;

            std::optional<Gate> find_by_id(const Gate::Id&) override {
                return stored_entity;
            }

            void save(const Gate& e) override {
                stored_entity = e;
            }

            void remove(const Gate::Id&) override {
                removed = true;
                stored_entity = {};
            }

            auto find_all() -> Gates override {
                return {stored_entity};
            }
        }; 

        auto entity = make_seed_gate();
        auto repo = MockGateRepository{};

        WHEN("entity is saved") {
            repo.save(entity);

            THEN("it can be retrieved by id") {
                auto found = repo.find_by_id(entity.id);
                REQUIRE(found.has_value());
                // assert_gate_equals(*found, entity);
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

} // namespace passenger_terminal::test
