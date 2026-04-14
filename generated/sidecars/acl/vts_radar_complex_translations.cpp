// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// MUSCOVITE:SIDECAR:UNMODIFIED — remove this line when editing this file

// #include "vts_radar_adapter.hpp"

namespace harbour_control {

auto VTSRadarAdapter::translate_radar_track_to_vessel_position(const RadarTrack& source) const -> VesselPosition {
    auto result = VesselPosition{};
    // TODO: implement complex field translations for RadarTrack → VesselPosition
    // result.mmsi = <complex expression>;
    // result.latitude = <complex expression>;
    // result.longitude = <complex expression>;
    // result.heading_degrees = <complex expression>;
    // result.speed_knots = <complex expression>;
    return result;
}

} // namespace harbour_control
