// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "parcel_command_service.hpp"

namespace cargo_decomposition {

auto ParcelCommandService::create(const Parcel& entity) -> void {
    repository_.save(entity);
}

auto ParcelCommandService::update(const Parcel& entity) -> void {
    repository_.save(entity);
}

auto ParcelCommandService::remove(const Parcel::Id& id) -> void {
    repository_.remove(id);
}

} // namespace cargo_decomposition
