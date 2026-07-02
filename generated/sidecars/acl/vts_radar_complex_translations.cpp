// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// MUSCOVITE:SIDECAR:UNMODIFIED — remove this line when editing this file

#include "../../harbour_control/acl/vts_radar_adapter.hpp"

namespace harbour_control {

auto VTSRadarAdapter::translate_radar_track_to_vessel_position(const RadarTrack& source) const -> VesselPosition {
    auto result = VesselPosition{};
    result.mmsi = source.radar_track;
    result.latitude = source.radar_track;
    result.longitude = source.radar_track;
    result.heading_degrees = source.radar_track;
    result.speed_knots = source.radar_track;
    return result;
}

} // namespace harbour_control
