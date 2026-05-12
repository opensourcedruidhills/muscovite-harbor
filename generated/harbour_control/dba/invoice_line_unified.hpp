#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace harbour_control {

/// Unified DBA struct for InvoiceLine.
struct InvoiceLine {
    boost::uuids::uuid id{};
    boost::uuids::uuid id{};
    boost::uuids::uuid vessel_id{};
    std::string service_type{};
    muscovite::dba::Decimal amount{};
    std::string currency{};
    muscovite::dba::Timestamp issued_at{};

    /// Construct from a database row (stub — implementation in .cpp).
    // static auto from_row(const pqxx::row& row) -> InvoiceLine;

    /// Try to construct; returns nullopt on missing required field.
    // static auto try_from(const pqxx::row& row) -> std::optional<InvoiceLine>;
};

} // namespace harbour_control
