#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "resource_identifier.hpp"
#include "nlohmann/json.hpp"

namespace security {

/// Serializes ResourceIdentifier to a JSON object for JSONB storage.
[[nodiscard]] inline auto to_jsonb(const ResourceIdentifier& v) -> nlohmann::json {
    auto j = nlohmann::json{};
    j["resource_type"] = v.resource_type;
    j["resource_id"] = v.resource_id;
    return j;
}

/// Deserializes ResourceIdentifier from a JSON object (JSONB retrieval).
[[nodiscard]] inline auto from_jsonb(const nlohmann::json& j) -> ResourceIdentifier {
    auto result = ResourceIdentifier{};
    result.resource_type = j.at("resource_type").get<std::string>();
    result.resource_id = j.at("resource_id").get<std::string>();
    return result;
}

} // namespace security
