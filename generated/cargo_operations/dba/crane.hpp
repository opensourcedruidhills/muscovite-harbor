#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <boost/uuid/uuid.hpp>
#include <muscovite/dba/decimal.hpp>
#include <string>
#include <string>

namespace cargo_operations {

/// A crane for container handling
struct Crane {
    using Id = boost::uuids::uuid;

    Id id{};
    std::string name{};
    std::string crane_type{};
    muscovite::dba::Decimal max_lift_kg{};
    bool is_active{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_name() const noexcept -> const std::string& { return name; }
    [[nodiscard]] auto get_crane_type() const noexcept -> const std::string& { return crane_type; }
    [[nodiscard]] auto get_max_lift_kg() const noexcept -> const muscovite::dba::Decimal& { return max_lift_kg; }
    [[nodiscard]] auto get_is_active() const noexcept -> bool { return is_active; }
};

} // namespace cargo_operations
