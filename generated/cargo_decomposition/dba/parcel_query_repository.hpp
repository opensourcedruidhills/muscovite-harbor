#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "parcel.hpp"
#include <cstdint>
#include <optional>
#include <vector>

namespace cargo_decomposition {

/// Query-side repository interface for Parcel aggregate.
/// Handles read operations (CQRS query side).
class ParcelQueryRepository {
public:
    virtual ~ParcelQueryRepository() = default;

    [[nodiscard]] virtual auto find_by_id(const Parcel::Id& id) -> std::optional<Parcel> = 0;
    [[nodiscard]] virtual auto find_all() -> std::vector<Parcel> = 0;
    [[nodiscard]] virtual auto count() -> std::int64_t = 0;
};

} // namespace cargo_decomposition
