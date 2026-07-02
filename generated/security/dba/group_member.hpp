#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <boost/uuid/uuid.hpp>

namespace security {

/// Join table linking Users to Groups (many-to-many).
struct GroupMember {
    using Id = boost::uuids::uuid;

    Id id{};
    boost::uuids::uuid group_id{};
    boost::uuids::uuid user_id{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_group_id() const noexcept -> const boost::uuids::uuid& { return group_id; }
    [[nodiscard]] auto get_user_id() const noexcept -> const boost::uuids::uuid& { return user_id; }
};

} // namespace security
