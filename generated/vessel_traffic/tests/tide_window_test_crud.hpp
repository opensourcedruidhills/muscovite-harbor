#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>
#include <optional>

// Forward declaration of repository for testing
namespace vessel_traffic { class TideWindowRepository; }

namespace vessel_traffic::test {

SCENARIO("TideWindow CRUD round-trip") {
    GIVEN("a mock repository and a seed TideWindow") {
        // Mock repository - in real use, this would be the generated repository
        struct MockTideWindowRepository : public TideWindowRepository {
            TideWindow stored_entity;
            bool removed = false;

            std::optional<TideWindow> find_by_id(const TideWindow::Id&) override {
                return stored_entity;
            }

            void save(const TideWindow& e) override {
                stored_entity = e;
            }

            void remove(const TideWindow::Id&) override {
                removed = true;
                stored_entity = {};
            }

            auto find_all() -> TideWindows override {
                return {stored_entity};
            }
        }; 

        auto entity = make_seed_tide_window();
        auto repo = MockTideWindowRepository{};

        WHEN("entity is saved") {
            repo.save(entity);

            THEN("it can be retrieved by id") {
                auto found = repo.find_by_id(entity.id);
                REQUIRE(found.has_value());
                // assert_tide_window_equals(*found, entity);
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

} // namespace vessel_traffic::test
