#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "geo_region.hpp"
#include "nlohmann/json.hpp"

namespace spatial {

/// Serializes GeoRegion to a JSON object for JSONB storage.
[[nodiscard]] inline auto to_jsonb(const GeoRegion& v) -> nlohmann::json {
    auto j = nlohmann::json{};
    j["ne"] = v.ne;
    j["sw"] = v.sw;
    return j;
}

/// Deserializes GeoRegion from a JSON object (JSONB retrieval).
[[nodiscard]] inline auto from_jsonb(const nlohmann::json& j) -> GeoRegion {
    auto result = GeoRegion{};
    result.ne = j.at("ne").get<std::string>();
    result.sw = j.at("sw").get<std::string>();
    return result;
}

} // namespace spatial
