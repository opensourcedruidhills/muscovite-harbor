#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>

namespace security {

/// Value-object struct for ResourceIdentifier.
struct ResourceIdentifier {
    std::string resource_type{};
    std::string resource_id{};

    auto operator==(const ResourceIdentifier&) const -> bool = default;
};

} // namespace security
