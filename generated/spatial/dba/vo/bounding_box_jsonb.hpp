#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "bounding_box.hpp"
#include "nlohmann/json.hpp"

namespace spatial {

/// Serializes BoundingBox to a JSON object for JSONB storage.
[[nodiscard]] inline auto to_jsonb(const BoundingBox& v) -> nlohmann::json {
    auto j = nlohmann::json{};
    j["min_lat"] = v.min_lat;
    j["min_lon"] = v.min_lon;
    j["max_lat"] = v.max_lat;
    j["max_lon"] = v.max_lon;
    return j;
}

/// Deserializes BoundingBox from a JSON object (JSONB retrieval).
[[nodiscard]] inline auto from_jsonb(const nlohmann::json& j) -> BoundingBox {
    auto result = BoundingBox{};
    result.min_lat = j.at("min_lat").get<muscovite::dba::Decimal>();
    result.min_lon = j.at("min_lon").get<muscovite::dba::Decimal>();
    result.max_lat = j.at("max_lat").get<muscovite::dba::Decimal>();
    result.max_lon = j.at("max_lon").get<muscovite::dba::Decimal>();
    return result;
}

} // namespace spatial
