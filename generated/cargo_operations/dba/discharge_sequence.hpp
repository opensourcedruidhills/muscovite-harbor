#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <boost/uuid/uuid.hpp>
#include <cstdint>
#include <string>

namespace cargo_operations {

/// Ordered sequence for container discharge
struct DischargeSequence {
    using Id = boost::uuids::uuid;

    Id id{};
    boost::uuids::uuid id{};
    boost::uuids::uuid load_plan_id{};
    boost::uuids::uuid container_id{};
    std::int32_t sequence_order{};
    boost::uuids::uuid crane_id{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_id() const noexcept -> const boost::uuids::uuid& { return id; }
    [[nodiscard]] auto get_load_plan_id() const noexcept -> const boost::uuids::uuid& { return load_plan_id; }
    [[nodiscard]] auto get_container_id() const noexcept -> const boost::uuids::uuid& { return container_id; }
    [[nodiscard]] auto get_sequence_order() const noexcept -> std::int32_t { return sequence_order; }
    [[nodiscard]] auto get_crane_id() const noexcept -> const boost::uuids::uuid& { return crane_id; }
};

} // namespace cargo_operations
