#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <boost/uuid/uuid.hpp>
#include <string>

namespace security {

/// Context-scoped privilege granted to a Group.
struct ContextPrivilege {
    using Id = boost::uuids::uuid;

    Id id{};
    std::string context_name{};
    boost::uuids::uuid group_id{};
    std::string privilege{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_context_name() const noexcept -> const std::string& { return context_name; }
    [[nodiscard]] auto get_group_id() const noexcept -> const boost::uuids::uuid& { return group_id; }
    [[nodiscard]] auto get_privilege() const noexcept -> const std::string& { return privilege; }
};

} // namespace security
