#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>

namespace security {

/// Single ACL entry: principal + resource + permission + allow/deny effect.
struct AccessControlEntry {
    using Id = std::string;

    Id id{};
    std::string principal{};
    std::string resource{};
    std::string permission{};
    std::string effect{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_principal() const noexcept -> const std::string& { return principal; }
    [[nodiscard]] auto get_resource() const noexcept -> const std::string& { return resource; }
    [[nodiscard]] auto get_permission() const noexcept -> const std::string& { return permission; }
    [[nodiscard]] auto get_effect() const noexcept -> const std::string& { return effect; }
};

} // namespace security
