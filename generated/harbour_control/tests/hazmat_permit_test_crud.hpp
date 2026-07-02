#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>
#include <optional>

// Forward declaration of repository for testing
namespace harbour_control { class HazmatPermitRepository; }

namespace harbour_control::test {

SCENARIO("HazmatPermit CRUD round-trip") {
    GIVEN("a mock repository and a seed HazmatPermit") {
        // Mock repository - in real use, this would be the generated repository
        struct MockHazmatPermitRepository : public HazmatPermitRepository {
            HazmatPermit stored_entity;
            bool removed = false;

            std::optional<HazmatPermit> find_by_id(const HazmatPermit::Id&) override {
                return stored_entity;
            }

            void save(const HazmatPermit& e) override {
                stored_entity = e;
            }

            void remove(const HazmatPermit::Id&) override {
                removed = true;
                stored_entity = {};
            }

            auto find_all() -> HazmatPermits override {
                return {stored_entity};
            }
        }; 

        auto entity = make_seed_hazmat_permit();
        auto repo = MockHazmatPermitRepository{};

        WHEN("entity is saved") {
            repo.save(entity);

            THEN("it can be retrieved by id") {
                auto found = repo.find_by_id(entity.id);
                REQUIRE(found.has_value());
                // assert_hazmat_permit_equals(*found, entity);
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
