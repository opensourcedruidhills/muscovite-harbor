#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <boost/uuid/uuid.hpp>
#include <cstdint>
#include <string>
#include <string>

namespace harbour_control {

/// Designated safety zone within the port area
struct SafetyZone {
    using Id = boost::uuids::uuid;

    Id id{};
    ZoneCode zone_code{};
    std::string zone_name{};
    std::string security_level{};
    std::int32_t max_hazmat_class{};
    bool is_restricted{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_zone_code() const noexcept -> const ZoneCode& { return zone_code; }
    [[nodiscard]] auto get_zone_name() const noexcept -> const std::string& { return zone_name; }
    [[nodiscard]] auto get_security_level() const noexcept -> const std::string& { return security_level; }
    [[nodiscard]] auto get_max_hazmat_class() const noexcept -> std::int32_t { return max_hazmat_class; }
    [[nodiscard]] auto get_is_restricted() const noexcept -> bool { return is_restricted; }
};

} // namespace harbour_control
