#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>

namespace security {

/// Named authorization group for role-based access control.
struct Group {
    using Id = boost::uuids::uuid;

    Id id{};
    std::string name{};
    std::string description{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_name() const noexcept -> const std::string& { return name; }
    [[nodiscard]] auto get_description() const noexcept -> const std::string& { return description; }
};

} // namespace security
