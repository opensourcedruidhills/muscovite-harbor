#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>
#include <optional>

// Forward declaration of repository for testing
namespace security { class ContextPrivilegeRepository; }

namespace security::test {

SCENARIO("ContextPrivilege CRUD round-trip") {
    GIVEN("a mock repository and a seed ContextPrivilege") {
        // Mock repository - in real use, this would be the generated repository
        struct MockContextPrivilegeRepository : public ContextPrivilegeRepository {
            ContextPrivilege stored_entity;
            bool removed = false;

            std::optional<ContextPrivilege> find_by_id(const ContextPrivilege::Id&) override {
                return stored_entity;
            }

            void save(const ContextPrivilege& e) override {
                stored_entity = e;
            }

            void remove(const ContextPrivilege::Id&) override {
                removed = true;
                stored_entity = {};
            }

            auto find_all() -> ContextPrivileges override {
                return {stored_entity};
            }
        }; 

        auto entity = make_seed_context_privilege();
        auto repo = MockContextPrivilegeRepository{};

        WHEN("entity is saved") {
            repo.save(entity);

            THEN("it can be retrieved by id") {
                auto found = repo.find_by_id(entity.id);
                REQUIRE(found.has_value());
                // assert_context_privilege_equals(*found, entity);
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
