#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>

namespace security {

/// Authenticated user with credential storage.
struct User {
    using Id = std::string;

    Id id{};
    std::string username{};
    std::string email{};
    std::string password_hash{};
    bool is_active{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_username() const noexcept -> const std::string& { return username; }
    [[nodiscard]] auto get_email() const noexcept -> const std::string& { return email; }
    [[nodiscard]] auto get_password_hash() const noexcept -> const std::string& { return password_hash; }
    [[nodiscard]] auto get_is_active() const noexcept -> bool { return is_active; }
};

} // namespace security
