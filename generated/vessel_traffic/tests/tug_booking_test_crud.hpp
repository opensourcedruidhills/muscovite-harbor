#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>
#include <optional>

// Forward declaration of repository for testing
namespace vessel_traffic { class TugBookingRepository; }

namespace vessel_traffic::test {

SCENARIO("TugBooking CRUD round-trip") {
    GIVEN("a mock repository and a seed TugBooking") {
        // Mock repository - in real use, this would be the generated repository
        struct MockTugBookingRepository : public TugBookingRepository {
            TugBooking stored_entity;
            bool removed = false;

            std::optional<TugBooking> find_by_id(const TugBooking::Id&) override {
                return stored_entity;
            }

            void save(const TugBooking& e) override {
                stored_entity = e;
            }

            void remove(const TugBooking::Id&) override {
                removed = true;
                stored_entity = {};
            }

            auto find_all() -> TugBookings override {
                return {stored_entity};
            }
        }; 

        auto entity = make_seed_tug_booking();
        auto repo = MockTugBookingRepository{};

        WHEN("entity is saved") {
            repo.save(entity);

            THEN("it can be retrieved by id") {
                auto found = repo.find_by_id(entity.id);
                REQUIRE(found.has_value());
                // assert_tug_booking_equals(*found, entity);
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
