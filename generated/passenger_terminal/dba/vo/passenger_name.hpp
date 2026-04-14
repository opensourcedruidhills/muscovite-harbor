#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>

namespace passenger_terminal {

/// Value object — compared by value, not identity.
struct PassengerName {
    std::string given_name{};
    std::string family_name{};

    [[nodiscard]] auto get_given_name() const noexcept -> const std::string& { return given_name; }
    [[nodiscard]] auto get_family_name() const noexcept -> const std::string& { return family_name; }

    auto operator==(const PassengerName&) const -> bool = default;
};

} // namespace passenger_terminal
