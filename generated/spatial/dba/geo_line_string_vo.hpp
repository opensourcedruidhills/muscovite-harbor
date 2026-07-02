#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>

namespace spatial {

/// Value-object struct for GeoLineString.
struct GeoLineString {
    std::string points{};

    auto operator==(const GeoLineString&) const -> bool = default;
};

} // namespace spatial
