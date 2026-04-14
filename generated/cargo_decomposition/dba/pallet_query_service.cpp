// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "pallet_query_service.hpp"

namespace cargo_decomposition {

auto PalletQueryService::find_by_id(const Pallet::Id& id) -> std::optional<Pallet> {
    return repository_.find_by_id(id);
}

auto PalletQueryService::find_all() -> std::vector<Pallet> {
    return repository_.find_all();
}

auto PalletQueryService::count() -> std::int64_t {
    return repository_.count();
}

} // namespace cargo_decomposition
