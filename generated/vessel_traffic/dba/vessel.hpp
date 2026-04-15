#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <boost/uuid/uuid.hpp>
#include <string>
#include <string>

namespace vessel_traffic {

/// A registered vessel in the harbour traffic system
struct Vessel {
    using Id = boost::uuids::uuid;

    Id id{};
    IMONumber imo_number{};
    MMSI mmsi{};
    CallSign call_sign{};
    std::string name{};
    std::string vessel_type{};
    std::string flag_state{};
    bool is_active{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_imo_number() const noexcept -> const IMONumber& { return imo_number; }
    [[nodiscard]] auto get_mmsi() const noexcept -> const MMSI& { return mmsi; }
    [[nodiscard]] auto get_call_sign() const noexcept -> const CallSign& { return call_sign; }
    [[nodiscard]] auto get_name() const noexcept -> const std::string& { return name; }
    [[nodiscard]] auto get_vessel_type() const noexcept -> const std::string& { return vessel_type; }
    [[nodiscard]] auto get_flag_state() const noexcept -> const std::string& { return flag_state; }
    [[nodiscard]] auto get_is_active() const noexcept -> bool { return is_active; }
};

} // namespace vessel_traffic
