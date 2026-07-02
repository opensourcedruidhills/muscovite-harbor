#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>
#include <optional>

// Forward declaration of repository for testing
namespace security { class AccessControlEntryRepository; }

namespace security::test {

SCENARIO("AccessControlEntry CRUD round-trip") {
    GIVEN("a mock repository and a seed AccessControlEntry") {
        // Mock repository - in real use, this would be the generated repository
        struct MockAccessControlEntryRepository : public AccessControlEntryRepository {
            AccessControlEntry stored_entity;
            bool removed = false;

            std::optional<AccessControlEntry> find_by_id(const AccessControlEntry::Id&) override {
                return stored_entity;
            }

            void save(const AccessControlEntry& e) override {
                stored_entity = e;
            }

            void remove(const AccessControlEntry::Id&) override {
                removed = true;
                stored_entity = {};
            }

            auto find_all() -> AccessControlEntrys override {
                return {stored_entity};
            }
        }; 

        auto entity = make_seed_access_control_entry();
        auto repo = MockAccessControlEntryRepository{};

        WHEN("entity is saved") {
            repo.save(entity);

            THEN("it can be retrieved by id") {
                auto found = repo.find_by_id(entity.id);
                REQUIRE(found.has_value());
                // assert_access_control_entry_equals(*found, entity);
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

} // namespace security::test
