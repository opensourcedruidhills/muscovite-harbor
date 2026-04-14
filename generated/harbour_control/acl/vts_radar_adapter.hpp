#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "foreign_types/vts_radar_types.hpp"
#include <string>

namespace harbour_control {

/// Vessel Traffic Service radar feed — government external system
/// Anti-corruption layer adapter for VTSRadar foreign context.
class VTSRadarAdapter {
public:

    [[nodiscard]] auto translate_radar_track_to_vessel_position(const RadarTrack& source) const -> VesselPosition;
};

} // namespace harbour_control
