// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "parcel_domain_service.hpp"
#include "nlohmann/json.hpp"
#include <stdexcept>
#include <string_view>

namespace cargo_decomposition {

auto ParcelDomainService::create(const Parcel& entity) -> void {
    // Tier 1+2: field constraints and cross-field invariants (EntityValidator)
    auto tier12_errors = ParcelValidator::validate(entity);
    if (!tier12_errors.empty()) { throw std::runtime_error("Tier 1/2 validation failed"); }

    // Tier 3: plugin validation (PluginValidator)
    auto tier3_errors = ParcelPluginValidator::validate(entity);
    if (!tier3_errors.empty()) { throw std::runtime_error("Tier 3 validation failed"); }

    command_service_.create(entity);
}

auto ParcelDomainService::update(const Parcel& entity) -> void {
    command_service_.update(entity);
}

auto ParcelDomainService::remove(const Parcel::Id& id) -> void {
    command_service_.remove(id);
}

auto ParcelDomainService::find_by_id(const Parcel::Id& id) -> std::optional<Parcel> {
    return query_service_.find_by_id(id);
}

auto ParcelDomainService::find_all() -> std::vector<Parcel> {
    return query_service_.find_all();
}

auto ParcelDomainService::add_delivery_unit(const Parcel::Id& parent_id, const DeliveryUnit& child) -> void {
    auto parent = query_service_.find_by_id(parent_id);
    if (!parent) {
        throw std::runtime_error("Parent Parcel not found");
    }
    command_service_.create(child);
}

auto ParcelDomainService::remove_delivery_unit(const Parcel::Id& parent_id, const DeliveryUnit::Id& child_id) -> void {
    (void)parent_id;
    command_service_.remove(child_id);
}

} // namespace cargo_decomposition
