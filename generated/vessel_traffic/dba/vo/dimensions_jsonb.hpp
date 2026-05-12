#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "dimensions.hpp"
#include "nlohmann/json.hpp"

namespace vessel_traffic {

/// Serializes Dimensions to a JSON object for JSONB storage.
[[nodiscard]] inline auto to_jsonb(const Dimensions& v) -> nlohmann::json {
    auto j = nlohmann::json{};
    j["loa_metres"] = v.loa_metres;
    j["beam_metres"] = v.beam_metres;
    j["draft_metres"] = v.draft_metres;
    return j;
}

/// Deserializes Dimensions from a JSON object (JSONB retrieval).
[[nodiscard]] inline auto from_jsonb(const nlohmann::json& j) -> Dimensions {
    auto result = Dimensions{};
    result.loa_metres = j.at("loa_metres").get<muscovite::dba::Decimal>();
    result.beam_metres = j.at("beam_metres").get<muscovite::dba::Decimal>();
    result.draft_metres = j.at("draft_metres").get<muscovite::dba::Decimal>();
    return result;
}

} // namespace vessel_traffic
