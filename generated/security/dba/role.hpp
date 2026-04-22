#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>

namespace security {

/// Named role aggregating a set of permissions.
struct Role {
    using Id = std::string;

    Id id{};
    std::string name{};
    std::string description{};
    std::string permissions{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_name() const noexcept -> const std::string& { return name; }
    [[nodiscard]] auto get_description() const noexcept -> const std::string& { return description; }
    [[nodiscard]] auto get_permissions() const noexcept -> const std::string& { return permissions; }
};

} // namespace security
