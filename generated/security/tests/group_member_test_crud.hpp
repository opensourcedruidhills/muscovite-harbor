#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>
#include <optional>

// Forward declaration of repository for testing
namespace security { class GroupMemberRepository; }

namespace security::test {

SCENARIO("GroupMember CRUD round-trip") {
    GIVEN("a mock repository and a seed GroupMember") {
        // Mock repository - in real use, this would be the generated repository
        struct MockGroupMemberRepository : public GroupMemberRepository {
            GroupMember stored_entity;
            bool removed = false;

            std::optional<GroupMember> find_by_id(const GroupMember::Id&) override {
                return stored_entity;
            }

            void save(const GroupMember& e) override {
                stored_entity = e;
            }

            void remove(const GroupMember::Id&) override {
                removed = true;
                stored_entity = {};
            }

            auto find_all() -> GroupMembers override {
                return {stored_entity};
            }
        }; 

        auto entity = make_seed_group_member();
        auto repo = MockGroupMemberRepository{};

        WHEN("entity is saved") {
            repo.save(entity);

            THEN("it can be retrieved by id") {
                auto found = repo.find_by_id(entity.id);
                REQUIRE(found.has_value());
                // assert_group_member_equals(*found, entity);
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
