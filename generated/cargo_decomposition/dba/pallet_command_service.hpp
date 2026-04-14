#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "pallet.hpp"
#include "pallet_command_repository.hpp"
#include <memory>
#include <string>

namespace cargo_decomposition {

/// Command service for Pallet aggregate.
/// Handles all write operations (CQRS command side).
class PalletCommandService {
public:
    explicit PalletCommandService(PalletCommandRepository& repository)
        : repository_{repository} {}

    auto create(const Pallet& entity) -> void;
    auto update(const Pallet& entity) -> void;
    auto remove(const Pallet::Id& id) -> void;

private:
    PalletCommandRepository& repository_;
};

} // namespace cargo_decomposition
