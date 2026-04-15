#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <boost/uuid/uuid.hpp>
#include <muscovite/dba/decimal.hpp>
#include <muscovite/dba/timestamp.hpp>
#include <string>
#include <string>

namespace harbour_control {

/// Port services invoice line item
struct InvoiceLine {
    using Id = boost::uuids::uuid;

    Id id{};
    boost::uuids::uuid vessel_id{};
    std::string service_type{};
    muscovite::dba::Decimal amount{};
    std::string currency{};
    muscovite::dba::Timestamp issued_at{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_vessel_id() const noexcept -> const boost::uuids::uuid& { return vessel_id; }
    [[nodiscard]] auto get_service_type() const noexcept -> const std::string& { return service_type; }
    [[nodiscard]] auto get_amount() const noexcept -> const muscovite::dba::Decimal& { return amount; }
    [[nodiscard]] auto get_currency() const noexcept -> const std::string& { return currency; }
    [[nodiscard]] auto get_issued_at() const noexcept -> const muscovite::dba::Timestamp& { return issued_at; }
};

} // namespace harbour_control
