#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "geo_crs.hpp"
#include "nlohmann/json.hpp"

namespace spatial {

/// Serializes GeoCRS to a JSON object for JSONB storage.
[[nodiscard]] inline auto to_jsonb(const GeoCRS& v) -> nlohmann::json {
    auto j = nlohmann::json{};
    j["identifier"] = v.identifier;
    return j;
}

/// Deserializes GeoCRS from a JSON object (JSONB retrieval).
[[nodiscard]] inline auto from_jsonb(const nlohmann::json& j) -> GeoCRS {
    auto result = GeoCRS{};
    result.identifier = j.at("identifier").get<std::string>();
    return result;
}

} // namespace spatial
