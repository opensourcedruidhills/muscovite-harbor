#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "weight.hpp"
#include "nlohmann/json.hpp"

namespace cargo_decomposition {

/// Serializes Weight to a JSON object for JSONB storage.
[[nodiscard]] inline auto to_jsonb(const Weight& v) -> nlohmann::json {
    auto j = nlohmann::json{};
    j["value_kg"] = v.value_kg;
    return j;
}

/// Deserializes Weight from a JSON object (JSONB retrieval).
[[nodiscard]] inline auto from_jsonb(const nlohmann::json& j) -> Weight {
    auto result = Weight{};
    result.value_kg = j.at("value_kg").get<muscovite::dba::Decimal>();
    return result;
}

} // namespace cargo_decomposition
