#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "parcel.hpp"
#include <optional>
#include <vector>

namespace cargo_decomposition {

/// Repository interface for Parcel aggregate.
class ParcelRepository {
public:
    using Parcels = std::vector<Parcel>;

    virtual ~ParcelRepository() = default;

    [[nodiscard]] virtual auto find_by_id(const Parcel::Id& id) -> std::optional<Parcel> = 0;
    virtual auto save(const Parcel& entity) -> void = 0;
    virtual auto remove(const Parcel::Id& id) -> void = 0;
    [[nodiscard]] virtual auto find_all() -> Parcels = 0;
};

} // namespace cargo_decomposition
