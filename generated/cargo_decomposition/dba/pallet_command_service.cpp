// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "pallet_command_service.hpp"

namespace cargo_decomposition {

auto PalletCommandService::create(const Pallet& entity) -> void {
    repository_.save(entity);
}

auto PalletCommandService::update(const Pallet& entity) -> void {
    repository_.save(entity);
}

auto PalletCommandService::remove(const Pallet::Id& id) -> void {
    repository_.remove(id);
}

} // namespace cargo_decomposition
