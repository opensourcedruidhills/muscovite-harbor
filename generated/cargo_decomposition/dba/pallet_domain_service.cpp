// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "pallet_domain_service.hpp"

namespace cargo_decomposition {

auto PalletDomainService::create(const Pallet& entity) -> void {
    // Tier 1: field-level constraints (handled by entity struct)
    // Tier 2: cross-field invariants (EntityValidator)
    // Tier 3: plugin validation (PluginValidator)
    command_service_.create(entity);
}

auto PalletDomainService::update(const Pallet& entity) -> void {
    command_service_.update(entity);
}

auto PalletDomainService::remove(const Pallet::Id& id) -> void {
    command_service_.remove(id);
}

auto PalletDomainService::find_by_id(const Pallet::Id& id) -> std::optional<Pallet> {
    return query_service_.find_by_id(id);
}

auto PalletDomainService::find_all() -> std::vector<Pallet> {
    return query_service_.find_all();
}

auto PalletDomainService::add_parcel(const Pallet::Id& parent_id, const Parcel& child) -> void {
    // Validate parent exists, then delegate to command service
    (void)parent_id; (void)child;
}

auto PalletDomainService::remove_parcel(const Pallet::Id& parent_id, const Parcel::Id& child_id) -> void {
    (void)parent_id; (void)child_id;
}

} // namespace cargo_decomposition
