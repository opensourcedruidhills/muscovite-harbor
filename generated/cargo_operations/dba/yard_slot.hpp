#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <boost/uuid/uuid.hpp>
#include <cstdint>
#include <string>

namespace cargo_operations {

/// A position in the container yard (bay-row-tier)
struct YardSlot {
    using Id = boost::uuids::uuid;

    Id id{};
    boost::uuids::uuid id{};
    YardSlotCode code{};
    muscovite::dba::Decimal max_weight_kg{};
    std::int32_t max_tier{};
    bool has_power{};
    bool is_occupied{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_id() const noexcept -> const boost::uuids::uuid& { return id; }
    [[nodiscard]] auto get_code() const noexcept -> const YardSlotCode& { return code; }
    [[nodiscard]] auto get_max_weight_kg() const noexcept -> const muscovite::dba::Decimal& { return max_weight_kg; }
    [[nodiscard]] auto get_max_tier() const noexcept -> std::int32_t { return max_tier; }
    [[nodiscard]] auto get_has_power() const noexcept -> bool { return has_power; }
    [[nodiscard]] auto get_is_occupied() const noexcept -> bool { return is_occupied; }
};

} // namespace cargo_operations
