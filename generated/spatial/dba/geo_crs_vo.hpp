#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>

namespace spatial {

/// Value-object struct for GeoCRS.
struct GeoCRS {
    std::string identifier{};

    auto operator==(const GeoCRS&) const -> bool = default;
};

} // namespace spatial
