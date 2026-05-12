#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "geo_position.hpp"
#include "nlohmann/json.hpp"

namespace vessel_traffic {

/// Serializes GeoPosition to a JSON object for JSONB storage.
[[nodiscard]] inline auto to_jsonb(const GeoPosition& v) -> nlohmann::json {
    auto j = nlohmann::json{};
    j["latitude"] = v.latitude;
    j["longitude"] = v.longitude;
    return j;
}

/// Deserializes GeoPosition from a JSON object (JSONB retrieval).
[[nodiscard]] inline auto from_jsonb(const nlohmann::json& j) -> GeoPosition {
    auto result = GeoPosition{};
    result.latitude = j.at("latitude").get<muscovite::dba::Decimal>();
    result.longitude = j.at("longitude").get<muscovite::dba::Decimal>();
    return result;
}

} // namespace vessel_traffic
