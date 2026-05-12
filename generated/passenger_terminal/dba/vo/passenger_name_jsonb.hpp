#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "passenger_name.hpp"
#include "nlohmann/json.hpp"

namespace passenger_terminal {

/// Serializes PassengerName to a JSON object for JSONB storage.
[[nodiscard]] inline auto to_jsonb(const PassengerName& v) -> nlohmann::json {
    auto j = nlohmann::json{};
    j["given_name"] = v.given_name;
    j["family_name"] = v.family_name;
    return j;
}

/// Deserializes PassengerName from a JSON object (JSONB retrieval).
[[nodiscard]] inline auto from_jsonb(const nlohmann::json& j) -> PassengerName {
    auto result = PassengerName{};
    result.given_name = j.at("given_name").get<std::string>();
    result.family_name = j.at("family_name").get<std::string>();
    return result;
}

} // namespace passenger_terminal
