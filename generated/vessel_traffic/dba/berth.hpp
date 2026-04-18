#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <boost/uuid/uuid.hpp>
#include <muscovite/dba/decimal.hpp>
#include <string>
#include "types/berth_code.hpp"

namespace vessel_traffic {

/// A physical berth where vessels moor
struct Berth {
    using Id = boost::uuids::uuid;

    Id id{};
    BerthCode code{};
    std::string name{};
    muscovite::dba::Decimal max_loa_metres{};
    muscovite::dba::Decimal max_draft_metres{};
    muscovite::dba::Decimal max_beam_metres{};
    bool has_crane_access{};
    bool has_reefer_plugs{};
    bool is_active{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_code() const noexcept -> const BerthCode& { return code; }
    [[nodiscard]] auto get_name() const noexcept -> const std::string& { return name; }
    [[nodiscard]] auto get_max_loa_metres() const noexcept -> const muscovite::dba::Decimal& { return max_loa_metres; }
    [[nodiscard]] auto get_max_draft_metres() const noexcept -> const muscovite::dba::Decimal& { return max_draft_metres; }
    [[nodiscard]] auto get_max_beam_metres() const noexcept -> const muscovite::dba::Decimal& { return max_beam_metres; }
    [[nodiscard]] auto get_has_crane_access() const noexcept -> bool { return has_crane_access; }
    [[nodiscard]] auto get_has_reefer_plugs() const noexcept -> bool { return has_reefer_plugs; }
    [[nodiscard]] auto get_is_active() const noexcept -> bool { return is_active; }
};

} // namespace vessel_traffic
