#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "pallet.hpp"
#include <optional>
#include <string>
#include <vector>

namespace cargo_decomposition {

/// Command-side repository interface for Pallet aggregate.
/// Handles write operations (create, update, delete).
class PalletCommandRepository {
public:
    virtual ~PalletCommandRepository() = default;

    virtual auto save(const Pallet& entity) -> void = 0;
    virtual auto remove(const Pallet::Id& id) -> void = 0;
    [[nodiscard]] virtual auto find_by_id(const Pallet::Id& id) -> std::optional<Pallet> = 0;
};

} // namespace cargo_decomposition
