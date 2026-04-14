#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <boost/uuid/uuid.hpp>
#include <cstdint>
#include <string>
#include <string>

namespace passenger_terminal {

/// A physical gate in the passenger terminal
struct Gate {
    using Id = boost::uuids::uuid;

    Id id{};
    boost::uuids::uuid id{};
    GateCode code{};
    std::string name{};
    std::int32_t capacity{};
    std::string status{};
    boost::uuids::uuid voyage_id{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_id() const noexcept -> const boost::uuids::uuid& { return id; }
    [[nodiscard]] auto get_code() const noexcept -> const GateCode& { return code; }
    [[nodiscard]] auto get_name() const noexcept -> const std::string& { return name; }
    [[nodiscard]] auto get_capacity() const noexcept -> std::int32_t { return capacity; }
    [[nodiscard]] auto get_status() const noexcept -> const std::string& { return status; }
    [[nodiscard]] auto get_voyage_id() const noexcept -> const boost::uuids::uuid& { return voyage_id; }
};

} // namespace passenger_terminal
