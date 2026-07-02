#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>
#include <optional>

// Forward declaration of repository for testing
namespace harbour_control { class InvoiceLineRepository; }

namespace harbour_control::test {

SCENARIO("InvoiceLine CRUD round-trip") {
    GIVEN("a mock repository and a seed InvoiceLine") {
        // Mock repository - in real use, this would be the generated repository
        struct MockInvoiceLineRepository : public InvoiceLineRepository {
            InvoiceLine stored_entity;
            bool removed = false;

            std::optional<InvoiceLine> find_by_id(const InvoiceLine::Id&) override {
                return stored_entity;
            }

            void save(const InvoiceLine& e) override {
                stored_entity = e;
            }

            void remove(const InvoiceLine::Id&) override {
                removed = true;
                stored_entity = {};
            }

            auto find_all() -> InvoiceLines override {
                return {stored_entity};
            }
        }; 

        auto entity = make_seed_invoice_line();
        auto repo = MockInvoiceLineRepository{};

        WHEN("entity is saved") {
            repo.save(entity);

            THEN("it can be retrieved by id") {
                auto found = repo.find_by_id(entity.id);
                REQUIRE(found.has_value());
                // assert_invoice_line_equals(*found, entity);
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
