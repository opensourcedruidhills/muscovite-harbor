#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "geo_point.hpp"
#include "nlohmann/json.hpp"

namespace spatial {

/// Serializes GeoPoint to a JSON object for JSONB storage.
[[nodiscard]] inline auto to_jsonb(const GeoPoint& v) -> nlohmann::json {
    auto j = nlohmann::json{};
    j["lat"] = v.lat;
    j["lon"] = v.lon;
    j["alt"] = v.alt;
    return j;
}

/// Deserializes GeoPoint from a JSON object (JSONB retrieval).
[[nodiscard]] inline auto from_jsonb(const nlohmann::json& j) -> GeoPoint {
    auto result = GeoPoint{};
    result.lat = j.at("lat").get<Double>();
    result.lon = j.at("lon").get<Double>();
    result.alt = j.at("alt").get<Double>();
    return result;
}

} // namespace spatial
