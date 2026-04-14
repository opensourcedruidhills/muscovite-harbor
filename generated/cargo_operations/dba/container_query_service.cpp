// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "container_query_service.hpp"

namespace cargo_operations {

auto ContainerQueryService::find_by_id(const Container::Id& id) -> std::optional<Container> {
    return repository_.find_by_id(id);
}

auto ContainerQueryService::find_all() -> std::vector<Container> {
    return repository_.find_all();
}

auto ContainerQueryService::count() -> std::int64_t {
    return repository_.count();
}

} // namespace cargo_operations
