#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "pallet.hpp"
#include <cstdint>
#include <optional>
#include <vector>

namespace cargo_decomposition {

/// Query-side repository interface for Pallet aggregate.
/// Handles read operations (CQRS query side).
class PalletQueryRepository {
public:
    virtual ~PalletQueryRepository() = default;

    [[nodiscard]] virtual auto find_by_id(const Pallet::Id& id) -> std::optional<Pallet> = 0;
    [[nodiscard]] virtual auto find_all() -> std::vector<Pallet> = 0;
    [[nodiscard]] virtual auto count() -> std::int64_t = 0;
};

} // namespace cargo_decomposition
