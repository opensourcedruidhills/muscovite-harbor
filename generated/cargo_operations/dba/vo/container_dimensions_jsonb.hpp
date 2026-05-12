#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "container_dimensions.hpp"
#include "nlohmann/json.hpp"

namespace cargo_operations {

/// Serializes ContainerDimensions to a JSON object for JSONB storage.
[[nodiscard]] inline auto to_jsonb(const ContainerDimensions& v) -> nlohmann::json {
    auto j = nlohmann::json{};
    j["length_ft"] = v.length_ft;
    j["weight_kg"] = v.weight_kg;
    j["is_reefer"] = v.is_reefer;
    return j;
}

/// Deserializes ContainerDimensions from a JSON object (JSONB retrieval).
[[nodiscard]] inline auto from_jsonb(const nlohmann::json& j) -> ContainerDimensions {
    auto result = ContainerDimensions{};
    result.length_ft = j.at("length_ft").get<std::int32_t>();
    result.weight_kg = j.at("weight_kg").get<muscovite::dba::Decimal>();
    result.is_reefer = j.at("is_reefer").get<bool>();
    return result;
}

} // namespace cargo_operations
