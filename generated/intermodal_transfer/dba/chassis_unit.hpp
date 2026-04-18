#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <boost/uuid/uuid.hpp>
#include <string>

namespace intermodal_transfer {

/// Chassis for container road transport
struct ChassisUnit {
    using Id = boost::uuids::uuid;

    Id id{};
    std::string chassis_number{};
    std::string chassis_type{};
    bool is_available{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_chassis_number() const noexcept -> const std::string& { return chassis_number; }
    [[nodiscard]] auto get_chassis_type() const noexcept -> const std::string& { return chassis_type; }
    [[nodiscard]] auto get_is_available() const noexcept -> bool { return is_available; }
};

} // namespace intermodal_transfer
