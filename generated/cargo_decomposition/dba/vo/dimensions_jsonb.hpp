#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "dimensions.hpp"
#include "nlohmann/json.hpp"

namespace cargo_decomposition {

/// Serializes Dimensions to a JSON object for JSONB storage.
[[nodiscard]] inline auto to_jsonb(const Dimensions& v) -> nlohmann::json {
    auto j = nlohmann::json{};
    j["length_cm"] = v.length_cm;
    j["width_cm"] = v.width_cm;
    j["height_cm"] = v.height_cm;
    return j;
}

/// Deserializes Dimensions from a JSON object (JSONB retrieval).
[[nodiscard]] inline auto from_jsonb(const nlohmann::json& j) -> Dimensions {
    auto result = Dimensions{};
    result.length_cm = j.at("length_cm").get<muscovite::dba::Decimal>();
    result.width_cm = j.at("width_cm").get<muscovite::dba::Decimal>();
    result.height_cm = j.at("height_cm").get<muscovite::dba::Decimal>();
    return result;
}

} // namespace cargo_decomposition
