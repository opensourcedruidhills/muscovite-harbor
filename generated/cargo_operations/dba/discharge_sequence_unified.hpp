#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace cargo_operations {

/// Unified DBA struct for DischargeSequence.
struct DischargeSequence {
    boost::uuids::uuid id{};
    boost::uuids::uuid id{};
    boost::uuids::uuid load_plan_id{};
    boost::uuids::uuid container_id{};
    std::int32_t sequence_order{};
    boost::uuids::uuid crane_id{};

    /// Construct from a database row (stub — implementation in .cpp).
    // static auto from_row(const pqxx::row& row) -> DischargeSequence;

    /// Try to construct; returns nullopt on missing required field.
    // static auto try_from(const pqxx::row& row) -> std::optional<DischargeSequence>;
};

} // namespace cargo_operations
