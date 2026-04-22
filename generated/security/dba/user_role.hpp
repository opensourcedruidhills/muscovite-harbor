#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>

namespace security {

/// Join table linking Users to Roles (many-to-many).
struct UserRole {
    using Id = std::string;

    Id id{};
    std::string user_id{};
    std::string role_id{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_user_id() const noexcept -> const std::string& { return user_id; }
    [[nodiscard]] auto get_role_id() const noexcept -> const std::string& { return role_id; }
};

} // namespace security
