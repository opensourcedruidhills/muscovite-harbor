#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <boost/uuid/uuid.hpp>
#include <muscovite/dba/decimal.hpp>
#include "types/hs_code.hpp"
#include "types/pallet_id.hpp"

namespace cargo_decomposition {

/// A pallet extracted from a container
struct Pallet {
    using Id = boost::uuids::uuid;

    Id id{};
    PalletId pallet_id{};
    boost::uuids::uuid container_id{};
    muscovite::dba::Decimal weight_kg{};
    muscovite::dba::Decimal length_cm{};
    muscovite::dba::Decimal width_cm{};
    muscovite::dba::Decimal height_cm{};
    HSCode hs_code{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_pallet_id() const noexcept -> const PalletId& { return pallet_id; }
    [[nodiscard]] auto get_container_id() const noexcept -> const boost::uuids::uuid& { return container_id; }
    [[nodiscard]] auto get_weight_kg() const noexcept -> const muscovite::dba::Decimal& { return weight_kg; }
    [[nodiscard]] auto get_length_cm() const noexcept -> const muscovite::dba::Decimal& { return length_cm; }
    [[nodiscard]] auto get_width_cm() const noexcept -> const muscovite::dba::Decimal& { return width_cm; }
    [[nodiscard]] auto get_height_cm() const noexcept -> const muscovite::dba::Decimal& { return height_cm; }
    [[nodiscard]] auto get_hs_code() const noexcept -> const HSCode& { return hs_code; }
};

} // namespace cargo_decomposition
