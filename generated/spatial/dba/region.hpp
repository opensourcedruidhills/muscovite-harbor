#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>

namespace spatial {

/// Named geographic region with boundary geometry and optional center point.
struct Region {
    using Id = std::string;

    Id id{};
    std::string name{};
    std::string boundary{};
    std::string center{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_name() const noexcept -> const std::string& { return name; }
    [[nodiscard]] auto get_boundary() const noexcept -> const std::string& { return boundary; }
    [[nodiscard]] auto get_center() const noexcept -> const std::string& { return center; }
};

} // namespace spatial
