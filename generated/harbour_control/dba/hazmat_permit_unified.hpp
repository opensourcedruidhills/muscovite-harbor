#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace harbour_control {

/// Unified DBA struct for HazmatPermit.
struct HazmatPermit {
    boost::uuids::uuid id{};
    PermitNumber permit_number{};
    boost::uuids::uuid vessel_id{};
    std::int32_t imo_class{};
    muscovite::dba::Decimal quantity_kg{};
    bool approved{};
    muscovite::dba::Timestamp valid_from{};
    muscovite::dba::Timestamp valid_until{};

    /// Construct from a database row.
    static auto from_row(const pqxx::row& row) -> HazmatPermit {
        return HazmatPermit{
            .id = row[0].as<std::string>(),
            .permit_number = row[1].as<std::string>(),
            .vessel_id = row[2].as<std::string>(),
            .imo_class = row[3].as<std::string>(),
            .quantity_kg = row[4].as<std::string>(),
            .approved = row[5].as<std::string>(),
            .valid_from = row[6].as<std::string>(),
            .valid_until = row[7].as<std::string>(),
        };
    }

    /// Try to construct; returns nullopt on missing required field.
    static auto try_from(const pqxx::row& row) -> std::optional<HazmatPermit> {
        if (row[0].is_null()) return std::nullopt;
        if (row[1].is_null()) return std::nullopt;
        if (row[2].is_null()) return std::nullopt;
        if (row[3].is_null()) return std::nullopt;
        if (row[4].is_null()) return std::nullopt;
        if (row[5].is_null()) return std::nullopt;
        if (row[6].is_null()) return std::nullopt;
        if (row[7].is_null()) return std::nullopt;
        return from_row(row);
    }
};

} // namespace harbour_control
