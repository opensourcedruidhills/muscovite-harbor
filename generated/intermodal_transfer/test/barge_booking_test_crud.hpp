#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>
#include <optional>

// Forward declaration of repository for testing
namespace intermodal_transfer { class BargeBookingRepository; }

namespace intermodal_transfer::test {

SCENARIO("BargeBooking CRUD round-trip") {
    GIVEN("a mock repository and a seed BargeBooking") {
        // Mock repository - in real use, this would be the generated repository
        struct MockBargeBookingRepository : public BargeBookingRepository {
            BargeBooking stored_entity;
            bool removed = false;

            std::optional<BargeBooking> find_by_id(const BargeBooking::Id&) override {
                return stored_entity;
            }

            void save(const BargeBooking& e) override {
                stored_entity = e;
            }

            void remove(const BargeBooking::Id&) override {
                removed = true;
                stored_entity = {};
            }

            auto find_all() -> BargeBookings override {
                return {stored_entity};
            }
        }; 

        auto entity = make_seed_barge_booking();
        auto repo = MockBargeBookingRepository{};

        WHEN("entity is saved") {
            repo.save(entity);

            THEN("it can be retrieved by id") {
                auto found = repo.find_by_id(entity.id);
                REQUIRE(found.has_value());
                // assert_barge_booking_equals(*found, entity);
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
