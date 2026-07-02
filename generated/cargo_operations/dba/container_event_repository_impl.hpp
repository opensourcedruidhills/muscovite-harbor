// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
//
// GENERATED FILE — DO NOT EDIT

#ifndef MUSCOVITEHARBOR_CARGOOPERATIONS_DBA_CONTAINER_EVENT_REPOSITORY_IMPL
#define MUSCOVITEHARBOR_CARGOOPERATIONS_DBA_CONTAINER_EVENT_REPOSITORY_IMPL

#include "container_event_repository.hpp"
#include <nlohmann/json.hpp>
#include <optional>
#include <stdexcept>
#include <string>
#include <vector>

namespace cargo_operations {

inline auto ContainerEventRepository::save(const Container& entity, std::int64_t version) -> void {
    (void)entity;
    (void)version;
}

inline auto ContainerEventRepository::load(const std::string& id) -> std::optional<Container> {
    (void)id;
    return std::nullopt;
}

} // namespace cargo_operations

#endif // MUSCOVITEHARBOR_CARGOOPERATIONS_DBA_CONTAINER_EVENT_REPOSITORY_IMPL
