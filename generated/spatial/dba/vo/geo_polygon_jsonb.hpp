#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "geo_polygon.hpp"
#include "nlohmann/json.hpp"

namespace spatial {

/// Serializes GeoPolygon to a JSON object for JSONB storage.
[[nodiscard]] inline auto to_jsonb(const GeoPolygon& v) -> nlohmann::json {
    auto j = nlohmann::json{};
    j["points"] = v.points;
    return j;
}

/// Deserializes GeoPolygon from a JSON object (JSONB retrieval).
[[nodiscard]] inline auto from_jsonb(const nlohmann::json& j) -> GeoPolygon {
    auto result = GeoPolygon{};
    result.points = j.at("points").get<std::string>();
    return result;
}

} // namespace spatial
