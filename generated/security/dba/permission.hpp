#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>

namespace security {

/// Fine-grained permission binding a resource to an allowed action.
struct Permission {
    using Id = std::string;

    Id id{};
    std::string name{};
    std::string resource{};
    std::string action{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_name() const noexcept -> const std::string& { return name; }
    [[nodiscard]] auto get_resource() const noexcept -> const std::string& { return resource; }
    [[nodiscard]] auto get_action() const noexcept -> const std::string& { return action; }
};

} // namespace security
