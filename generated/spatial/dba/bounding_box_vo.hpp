#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <string>

namespace spatial {

/// Value-object struct for BoundingBox.
struct BoundingBox {
    muscovite::dba::Decimal min_lat{};
    muscovite::dba::Decimal min_lon{};
    muscovite::dba::Decimal max_lat{};
    muscovite::dba::Decimal max_lon{};

    auto operator==(const BoundingBox&) const -> bool = default;
};

} // namespace spatial
