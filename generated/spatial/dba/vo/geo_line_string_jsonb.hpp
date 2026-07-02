#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "geo_line_string.hpp"
#include "nlohmann/json.hpp"

namespace spatial {

/// Serializes GeoLineString to a JSON object for JSONB storage.
[[nodiscard]] inline auto to_jsonb(const GeoLineString& v) -> nlohmann::json {
    auto j = nlohmann::json{};
    j["points"] = v.points;
    return j;
}

/// Deserializes GeoLineString from a JSON object (JSONB retrieval).
[[nodiscard]] inline auto from_jsonb(const nlohmann::json& j) -> GeoLineString {
    auto result = GeoLineString{};
    result.points = j.at("points").get<std::string>();
    return result;
}

} // namespace spatial
