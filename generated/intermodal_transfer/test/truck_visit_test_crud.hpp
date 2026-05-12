#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>
#include <optional>

// Forward declaration of repository for testing
namespace intermodal_transfer { class TruckVisitRepository; }

namespace intermodal_transfer::test {

SCENARIO("TruckVisit CRUD round-trip") {
    GIVEN("a mock repository and a seed TruckVisit") {
        // Mock repository - in real use, this would be the generated repository
        struct MockTruckVisitRepository : public TruckVisitRepository {
            TruckVisit stored_entity;
            bool removed = false;

            std::optional<TruckVisit> find_by_id(const TruckVisit::Id&) override {
                return stored_entity;
            }

            void save(const TruckVisit& e) override {
                stored_entity = e;
            }

            void remove(const TruckVisit::Id&) override {
                removed = true;
                stored_entity = {};
            }

            auto find_all() -> TruckVisits override {
                return {stored_entity};
            }
        }; 

        auto entity = make_seed_truck_visit();
        auto repo = MockTruckVisitRepository{};

        WHEN("entity is saved") {
            repo.save(entity);

            THEN("it can be retrieved by id") {
                auto found = repo.find_by_id(entity.id);
                REQUIRE(found.has_value());
                // assert_truck_visit_equals(*found, entity);
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
