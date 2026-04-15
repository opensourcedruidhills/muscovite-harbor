#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <boost/uuid/uuid.hpp>
#include <muscovite/dba/decimal.hpp>
#include <string>
#include <string>

namespace intermodal_transfer {

/// A rail wagon for container transport
struct RailWagon {
    using Id = boost::uuids::uuid;

    Id id{};
    std::string wagon_number{};
    muscovite::dba::Decimal max_weight_kg{};
    boost::uuids::uuid slot_id{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_wagon_number() const noexcept -> const std::string& { return wagon_number; }
    [[nodiscard]] auto get_max_weight_kg() const noexcept -> const muscovite::dba::Decimal& { return max_weight_kg; }
    [[nodiscard]] auto get_slot_id() const noexcept -> const boost::uuids::uuid& { return slot_id; }
};

} // namespace intermodal_transfer
