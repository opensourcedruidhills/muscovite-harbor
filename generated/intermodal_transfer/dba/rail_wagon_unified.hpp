#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace intermodal_transfer {

/// Unified DBA struct for RailWagon.
struct RailWagon {
    boost::uuids::uuid id{};
    boost::uuids::uuid id{};
    std::string wagon_number{};
    muscovite::dba::Decimal max_weight_kg{};
    boost::uuids::uuid slot_id{};

    /// Construct from a database row (stub — implementation in .cpp).
    // static auto from_row(const pqxx::row& row) -> RailWagon;

    /// Try to construct; returns nullopt on missing required field.
    // static auto try_from(const pqxx::row& row) -> std::optional<RailWagon>;
};

} // namespace intermodal_transfer
