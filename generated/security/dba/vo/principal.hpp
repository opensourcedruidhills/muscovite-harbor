#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>

namespace security {

/// Identity of an actor (user, service account, or system).
/// Value object — compared by value, not identity.
struct Principal {
    std::string identifier{};

    [[nodiscard]] auto get_identifier() const noexcept -> const std::string& { return identifier; }

    auto operator==(const Principal&) const -> bool = default;
};

} // namespace security
