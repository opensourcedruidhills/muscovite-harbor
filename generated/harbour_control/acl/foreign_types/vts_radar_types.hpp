#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>
#include <string>

namespace harbour_control {

/// Raw radar track from VTS system
/// Foreign type from VTSRadar context.
struct RadarTrack {
    std::string mmsi{};
    muscovite::dba::Decimal lat{};
    muscovite::dba::Decimal lon{};
    muscovite::dba::Decimal heading{};
    muscovite::dba::Decimal speed{};
};

/// Translated vessel position from radar data
/// Foreign type from VTSRadar context.
struct VesselPosition {
    std::string mmsi{};
    muscovite::dba::Decimal latitude{};
    muscovite::dba::Decimal longitude{};
    muscovite::dba::Decimal heading_degrees{};
    muscovite::dba::Decimal speed_knots{};
};

} // namespace harbour_control
