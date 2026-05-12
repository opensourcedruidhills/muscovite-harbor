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
    boost::uuids::uuid id{};
    PermitNumber permit_number{};
    boost::uuids::uuid vessel_id{};
    std::int32_t imo_class{};
    muscovite::dba::Decimal quantity_kg{};
    bool approved{};
    muscovite::dba::Timestamp valid_from{};
    muscovite::dba::Timestamp valid_until{};

    /// Construct from a database row (stub — implementation in .cpp).
    // static auto from_row(const pqxx::row& row) -> HazmatPermit;

    /// Try to construct; returns nullopt on missing required field.
    // static auto try_from(const pqxx::row& row) -> std::optional<HazmatPermit>;
};

} // namespace harbour_control
