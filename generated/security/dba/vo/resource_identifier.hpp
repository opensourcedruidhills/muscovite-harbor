#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>

namespace security {

/// Typed reference to a protected resource.
/// Value object — compared by value, not identity.
struct ResourceIdentifier {
    std::string resource_type{};
    std::string resource_id{};

    [[nodiscard]] auto get_resource_type() const noexcept -> const std::string& { return resource_type; }
    [[nodiscard]] auto get_resource_id() const noexcept -> const std::string& { return resource_id; }

    auto operator==(const ResourceIdentifier&) const -> bool = default;
};

} // namespace security
