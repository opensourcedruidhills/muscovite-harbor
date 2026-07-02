#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <boost/uuid/uuid.hpp>

namespace security {

/// Join table linking Users to Roles (many-to-many).
struct UserRole {
    using Id = boost::uuids::uuid;

    Id id{};
    boost::uuids::uuid user_id{};
    boost::uuids::uuid role_id{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_user_id() const noexcept -> const boost::uuids::uuid& { return user_id; }
    [[nodiscard]] auto get_role_id() const noexcept -> const boost::uuids::uuid& { return role_id; }
};

} // namespace security
