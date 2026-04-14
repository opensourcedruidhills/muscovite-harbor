#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "pallet.hpp"
#include "pallet_query_repository.hpp"
#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace cargo_decomposition {

/// Query service for Pallet aggregate.
/// Handles all read operations (CQRS query side).
class PalletQueryService {
public:
    explicit PalletQueryService(PalletQueryRepository& repository)
        : repository_{repository} {}

    [[nodiscard]] auto find_by_id(const Pallet::Id& id) -> std::optional<Pallet>;
    [[nodiscard]] auto find_all() -> std::vector<Pallet>;
    [[nodiscard]] auto count() -> std::int64_t;

private:
    PalletQueryRepository& repository_;
};

} // namespace cargo_decomposition
