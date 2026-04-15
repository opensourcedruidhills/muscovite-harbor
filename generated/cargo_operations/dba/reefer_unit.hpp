#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <boost/uuid/uuid.hpp>
#include <muscovite/dba/decimal.hpp>
#include <string>

namespace cargo_operations {

/// Refrigeration monitoring unit for a reefer container
struct ReeferUnit {
    using Id = boost::uuids::uuid;

    Id id{};
    boost::uuids::uuid container_id{};
    muscovite::dba::Decimal target_temp_c{};
    muscovite::dba::Decimal current_temp_c{};
    bool is_powered{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_container_id() const noexcept -> const boost::uuids::uuid& { return container_id; }
    [[nodiscard]] auto get_target_temp_c() const noexcept -> const muscovite::dba::Decimal& { return target_temp_c; }
    [[nodiscard]] auto get_current_temp_c() const noexcept -> const muscovite::dba::Decimal& { return current_temp_c; }
    [[nodiscard]] auto get_is_powered() const noexcept -> bool { return is_powered; }
};

} // namespace cargo_operations
