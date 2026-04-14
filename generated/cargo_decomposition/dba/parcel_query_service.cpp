// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "parcel_query_service.hpp"

namespace cargo_decomposition {

auto ParcelQueryService::find_by_id(const Parcel::Id& id) -> std::optional<Parcel> {
    return repository_.find_by_id(id);
}

auto ParcelQueryService::find_all() -> std::vector<Parcel> {
    return repository_.find_all();
}

auto ParcelQueryService::count() -> std::int64_t {
    return repository_.count();
}

} // namespace cargo_decomposition
