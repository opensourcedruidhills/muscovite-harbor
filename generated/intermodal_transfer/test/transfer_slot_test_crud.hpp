#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>
#include <optional>

// Forward declaration of repository for testing
namespace intermodal_transfer { class TransferSlotRepository; }

namespace intermodal_transfer::test {

SCENARIO("TransferSlot CRUD round-trip") {
    GIVEN("a mock repository and a seed TransferSlot") {
        // Mock repository - in real use, this would be the generated repository
        struct MockTransferSlotRepository : public TransferSlotRepository {
            TransferSlot stored_entity;
            bool removed = false;

            std::optional<TransferSlot> find_by_id(const TransferSlot::Id&) override {
                return stored_entity;
            }

            void save(const TransferSlot& e) override {
                stored_entity = e;
            }

            void remove(const TransferSlot::Id&) override {
                removed = true;
                stored_entity = {};
            }

            auto find_all() -> TransferSlots override {
                return {stored_entity};
            }
        }; 

        auto entity = make_seed_transfer_slot();
        auto repo = MockTransferSlotRepository{};

        WHEN("entity is saved") {
            repo.save(entity);

            THEN("it can be retrieved by id") {
                auto found = repo.find_by_id(entity.id);
                REQUIRE(found.has_value());
                // assert_transfer_slot_equals(*found, entity);
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
