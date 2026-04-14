#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <boost/uuid/uuid.hpp>
#include <string>
#include <string>

namespace cargo_decomposition {

/// Non-containerised cargo item requiring special handling
struct BreakBulkItem {
    using Id = boost::uuids::uuid;

    Id id{};
    boost::uuids::uuid id{};
    boost::uuids::uuid container_id{};
    std::string item_type{};
    muscovite::dba::Decimal weight_kg{};
    bool requires_crane{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_id() const noexcept -> const boost::uuids::uuid& { return id; }
    [[nodiscard]] auto get_container_id() const noexcept -> const boost::uuids::uuid& { return container_id; }
    [[nodiscard]] auto get_item_type() const noexcept -> const std::string& { return item_type; }
    [[nodiscard]] auto get_weight_kg() const noexcept -> const muscovite::dba::Decimal& { return weight_kg; }
    [[nodiscard]] auto get_requires_crane() const noexcept -> bool { return requires_crane; }
};

} // namespace cargo_decomposition
