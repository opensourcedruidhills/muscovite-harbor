#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "time_window.hpp"
#include "nlohmann/json.hpp"

namespace vessel_traffic {

/// Serializes TimeWindow to a JSON object for JSONB storage.
[[nodiscard]] inline auto to_jsonb(const TimeWindow& v) -> nlohmann::json {
    auto j = nlohmann::json{};
    j["window_start"] = v.window_start;
    j["window_end"] = v.window_end;
    return j;
}

/// Deserializes TimeWindow from a JSON object (JSONB retrieval).
[[nodiscard]] inline auto from_jsonb(const nlohmann::json& j) -> TimeWindow {
    auto result = TimeWindow{};
    result.window_start = j.at("window_start").get<muscovite::dba::Timestamp>();
    result.window_end = j.at("window_end").get<muscovite::dba::Timestamp>();
    return result;
}

} // namespace vessel_traffic
