#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace vessel_traffic {

/// Value object — compared by value, not identity.
struct Dimensions {
    muscovite::dba::Decimal loa_metres{};
    muscovite::dba::Decimal beam_metres{};
    muscovite::dba::Decimal draft_metres{};

    [[nodiscard]] auto get_loa_metres() const noexcept -> const muscovite::dba::Decimal& { return loa_metres; }
    [[nodiscard]] auto get_beam_metres() const noexcept -> const muscovite::dba::Decimal& { return beam_metres; }
    [[nodiscard]] auto get_draft_metres() const noexcept -> const muscovite::dba::Decimal& { return draft_metres; }

    auto operator==(const Dimensions&) const -> bool = default;
};

} // namespace vessel_traffic
