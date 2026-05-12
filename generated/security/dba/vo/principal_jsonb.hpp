#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "principal.hpp"
#include "nlohmann/json.hpp"

namespace security {

/// Serializes Principal to a JSON object for JSONB storage.
[[nodiscard]] inline auto to_jsonb(const Principal& v) -> nlohmann::json {
    auto j = nlohmann::json{};
    j["identifier"] = v.identifier;
    return j;
}

/// Deserializes Principal from a JSON object (JSONB retrieval).
[[nodiscard]] inline auto from_jsonb(const nlohmann::json& j) -> Principal {
    auto result = Principal{};
    result.identifier = j.at("identifier").get<std::string>();
    return result;
}

} // namespace security
