// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "pallet_domain_service.hpp"
#include "nlohmann/json.hpp"
#include <stdexcept>
#include <string_view>

namespace cargo_decomposition {

auto PalletDomainService::create(const Pallet& entity) -> void {
    // Tier 1+2: field constraints and cross-field invariants (EntityValidator)
    auto tier12_errors = PalletValidator::validate(entity);
    if (!tier12_errors.empty()) { throw std::runtime_error("Tier 1/2 validation failed"); }

    // Tier 3: plugin validation (PluginValidator)
    auto tier3_errors = PalletPluginValidator::validate(entity);
    if (!tier3_errors.empty()) { throw std::runtime_error("Tier 3 validation failed"); }

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

} // namespace cargo_decomposition
