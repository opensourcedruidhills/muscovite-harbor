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
    boost::uuids::uuid vessel_id{};
    std::string service_type{};
    muscovite::dba::Decimal amount{};
    std::string currency{};
    muscovite::dba::Timestamp issued_at{};

    /// Construct from a database row.
    static auto from_row(const pqxx::row& row) -> InvoiceLine {
        return InvoiceLine{
            .id = row[0].as<std::string>(),
            .vessel_id = row[1].as<std::string>(),
            .service_type = row[2].as<std::string>(),
            .amount = row[3].as<std::string>(),
            .currency = row[4].as<std::string>(),
            .issued_at = row[5].as<std::string>(),
        };
    }

    /// Try to construct; returns nullopt on missing required field.
    static auto try_from(const pqxx::row& row) -> std::optional<InvoiceLine> {
        if (row[0].is_null()) return std::nullopt;
        if (row[1].is_null()) return std::nullopt;
        if (row[2].is_null()) return std::nullopt;
        if (row[3].is_null()) return std::nullopt;
        if (row[4].is_null()) return std::nullopt;
        if (row[5].is_null()) return std::nullopt;
        return from_row(row);
    }
};

} // namespace harbour_control
