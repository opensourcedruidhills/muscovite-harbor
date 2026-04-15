#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <muscovite/dba/timestamp.hpp>

namespace vessel_traffic {

/// Value object — compared by value, not identity.
struct TimeWindow {
    muscovite::dba::Timestamp window_start{};
    muscovite::dba::Timestamp window_end{};

    [[nodiscard]] auto get_window_start() const noexcept -> const muscovite::dba::Timestamp& { return window_start; }
    [[nodiscard]] auto get_window_end() const noexcept -> const muscovite::dba::Timestamp& { return window_end; }

    auto operator==(const TimeWindow&) const -> bool = default;
};

} // namespace vessel_traffic
