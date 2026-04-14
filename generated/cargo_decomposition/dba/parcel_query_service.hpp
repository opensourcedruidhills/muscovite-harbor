#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "parcel.hpp"
#include "parcel_query_repository.hpp"
#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace cargo_decomposition {

/// Query service for Parcel aggregate.
/// Handles all read operations (CQRS query side).
class ParcelQueryService {
public:
    explicit ParcelQueryService(ParcelQueryRepository& repository)
        : repository_{repository} {}

    [[nodiscard]] auto find_by_id(const Parcel::Id& id) -> std::optional<Parcel>;
    [[nodiscard]] auto find_all() -> std::vector<Parcel>;
    [[nodiscard]] auto count() -> std::int64_t;

private:
    ParcelQueryRepository& repository_;
};

} // namespace cargo_decomposition
